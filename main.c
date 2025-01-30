#include <gtk/gtk.h>

char *header;
GtkApplication *app;
GtkWindow *win;
GtkPasswordEntry *input;
int exit_code;

void quit(int code) {
  exit_code = code;
  g_application_quit(G_APPLICATION(app));
}

void on_confirm() {
  const char *pass = gtk_editable_get_text(GTK_EDITABLE(input));
  printf("%s\n", pass);
  quit(EXIT_SUCCESS);
}

void on_cancel() { quit(EXIT_FAILURE); }

bool on_key_press(GtkEventControllerKey *, guint keyval, guint, GdkModifierType,
                  gpointer) {
  if (strcmp(gdk_keyval_name(keyval), "Escape") == 0) {
    on_cancel();
    return TRUE;
  } else if (strcmp(gdk_keyval_name(keyval), "Return") == 0) {
    on_confirm();
    return TRUE;
  }

  return FALSE;
}

void on_activate() {
  win = GTK_WINDOW(gtk_window_new());
  gtk_window_set_application(win, app);

  GtkWidget *form = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  gtk_window_set_child(win, form);

  GtkWidget *label = gtk_label_new(header);

  input = GTK_PASSWORD_ENTRY(gtk_password_entry_new());

  GtkWidget *buttons = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 30);
  GtkWidget *confirm = gtk_button_new();
  gtk_button_set_label(GTK_BUTTON(confirm), "Confirm");
  GtkWidget *cancel = gtk_button_new();
  gtk_button_set_label(GTK_BUTTON(cancel), "Cancel");
  gtk_box_append(GTK_BOX(buttons), confirm);
  gtk_box_append(GTK_BOX(buttons), cancel);

  gtk_box_append(GTK_BOX(form), label);
  gtk_box_append(GTK_BOX(form), GTK_WIDGET(input));
  gtk_box_append(GTK_BOX(form), buttons);

  g_signal_connect(confirm, "clicked", on_confirm, NULL);
  g_signal_connect(cancel, "clicked", on_cancel, NULL);

  GtkEventController *ctrl = gtk_event_controller_key_new();
  g_signal_connect(ctrl, "key-pressed", G_CALLBACK(on_key_press), NULL);
  gtk_event_controller_set_propagation_phase(ctrl, GTK_PHASE_CAPTURE);
  gtk_widget_add_controller(GTK_WIDGET(win), ctrl);

  gtk_window_set_modal(win, TRUE);
  gtk_window_present(win);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: gaskpass \"cmd arg1 arg2\"\n");
    return EXIT_FAILURE;
  }
  header = argv[1];

  app = gtk_application_new("org.me.Gaskpass", G_APPLICATION_DEFAULT_FLAGS);

  g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

  g_application_run(G_APPLICATION(app), 0, NULL);

  return exit_code;
}
