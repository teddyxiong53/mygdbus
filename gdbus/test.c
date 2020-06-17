#include "gdbus.h"
static DBusConnection *dbus_conn;

static GMainLoop *main_loop;

void mainloop_init(void)
{
	main_loop = g_main_loop_new(NULL, FALSE);
}

static void connect_handler(DBusConnection *connection, void *user_data)
{
	printf("connect\n");
}

static void disconnect_handler(DBusConnection *connection, void *user_data)
{
    printf("disconnect\n");
}
int main()
{
    mainloop_init();
    GDBusClient *client;
    dbus_conn = g_dbus_setup_bus(DBUS_BUS_SYSTEM, NULL, NULL);
    client = g_dbus_client_new(dbus_conn, "org.freedesktop.DBus", "/org/freedesktop/DBus");
    g_dbus_client_set_connect_watch(client, connect_handler, NULL);
    g_dbus_client_set_disconnect_watch(client, disconnect_handler, NULL);

    g_main_loop_run(main_loop);

}
