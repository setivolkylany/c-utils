/**
 * Utils for a system
 *
 * https://pythonhosted.org/psutil/
 */


#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <stdio.h>
#include <stdbool.h>
#include <errno.h>

// #include <gtk/gtk.h>

#include "platform.h"

#if IS_POSIX_SYSTEM == 1

    #include <unistd.h>

    #include <sys/statvfs.h>
    #include <sys/utsname.h>
    #include <sys/sysinfo.h>

    #include <X11/Xlib.h>
#endif


extern int errno;


struct statusMemory {
    long unsigned int cache;
    long unsigned int free;
    long unsigned int used;
    long unsigned int total;
};


// Not implemented
// Return a current CPU usage of the system
float
system_get_total_cpu_usage()
{
    return 0;
}


/*
    Fills struct memory usage for whole system is passed NULL
    otherwise for process id.
 */
int
system_get_memory_status(const int process_id)
{
    return 0;
}


unsigned long int
system_get_memory_ram()
{
    return 0;
}


unsigned long int
system_get_memory_swap()
{
    return 0;
}


unsigned long int
system_get_memory_total()
{
    return 0;
}


unsigned long int
system_get_memory_cache()
{
    return 0;
}


int
system_get_hardware_list()
{
    return 0;
}


char *
system_get_architerture()
{
    return NULL;
}


// http://www.thegeekstuff.com/2011/04/identify-file-system-type/?utm_source=twitterfeed&utm_medium=twitter
// Show information about the file system on which each FILE resides, or all file systems by default
bool
system_filesystem_info()
{
    if (IS_POSIX_SYSTEM != 1)
        return false;

    struct statvfs stat;
    unsigned long long free_space;

    const char *paths[] = {
        "/media/setivolkylany/WorkDisk",
        "/",
        "/run",
        "/dev",
        "/unknown",
    };

    printf("%-30s | %s", "Device", "Free space\n");
    puts("-------------------------------------------------");
    for (int i = 0; i < 5; ++i) {
        if ((statvfs(paths[i], &stat)) == -1) {
            free_space = -1;
            return false;
        }
        free_space = (unsigned long long)(stat.f_bsize * stat.f_bavail) / 1;
        printf("%30s | %lli\n", paths[i], free_space);
    }

    return true;
}


// Summarize disk usage of each FILE, recursively for directories.
int
system_disk_usage()
{
    return 0;
}


/*
    Printing a current screen resoltion by using the GTK+3
    https://en.wikipedia.org/wiki/GTK%2B
 */
int
system_print_screen_resolution_by_GTK(int argc, char *argv[])
{
    /*
    GdkScreen *screen;
    gint width, height;

    gtk_init(&argc, &argv);

    if ((screen = gdk_screen_get_default()) != NULL) {
        width = gdk_screen_get_width(screen);
        height = gdk_screen_get_height(screen);
        g_printf("Current screen resolution: %dx%d (by used GTK+)\n", width, height);
    }
    */
    return 0;
}


/*
    Printing a current screen resoltion by using the libX11 (worked only for Unix-like OS)
    https://en.wikipedia.org/wiki/X_Window_System

    Based on:
        https://www.x.org/releases/X11R7.6/doc/libX11/specs/libX11/libX11.html
        http://surfingtroves.blogspot.com/2011/01/how-to-get-screen-resolution-in-linux-c.html
 */
int
system_print_display_resolution_by_X11()
{
    /*
    Display *display;
    Window window;
    XWindowAttributes xw_attrs;

    if ((display = XOpenDisplay(NULL)) == NULL) {
        fprintf(stderr, "Failed to open default display\n");
        return -1;
    }

    window = DefaultRootWindow(display);

    XGetWindowAttributes(display, window, &xw_attrs);

    printf("Current window resolution: %dx%d (by used X11)\n", xw_attrs.width, xw_attrs.height);

    XCloseDisplay(display);
    */
    return 0;
}


unsigned short int
system_count_kernels()
{
    putd(get_nprocs_conf());
    putd(get_nprocs());
    return sysconf(_SC_NPROCESSORS_ONLN);
}


void
system_byteorder()
{

}


unsigned short int
system_get_temperature()
{
    return 0;
}


#endif // __SYSTEM_H__
