#include "anti_emulator.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <dlfcn.h>

// long syscall(long number, ...);
typedef long (*SYSCALL_FUNCTION)(long, ...);

// int open(const char *pathname, int flags);
typedef int (*OPEN_FUNCTION)(const char *, int);

// int close(int fd);
typedef int (*CLOSE_FUNCTION)(int);

struct file_location {
    const char *directory;
    const char *file;
};

// Initialize function pointer
static void vsfnnnnedn();

// Check characteristic file, return -1 is emulator
static int mmghsshshhs_cdcd();

static const struct file_location g_characteristic_file_location_set[] = {
    { "/system/bin/", "mount.vboxsf" },
    { "/system/bin/", "nox-vbox-sf" },
    { "/system/lib/", "vboxguest.ko" },
    { "/system/lib/", "vboxsf.ko" },
    { "/sys/bus/pci/drivers/", "vboxguest" },
    { "/sys/devices/virtual/bdi/", "vboxsf-1" },
    { "/sys/devices/virtual/bdi/", "vboxsf-2" },
    { "/sys/devices/virtual/bdi/", "vboxsf-3" },
    { "/sys/devices/virtual/bdi/", "vboxsf-4" },
    { "/sys/devices/virtual/bdi/", "vboxsf-5" },
    { "/sys/devices/virtual/bdi/", "vboxsf-6" },
    { "/sys/devices/virtual/misc/", "vboxuser" },
    { "/sys/devices/virtual/misc/", "vboxguest" },
    { "/sys/class/bdi/", "vboxsf-1" },
    { "/sys/class/bdi/", "vboxsf-2" },
    { "/sys/class/bdi/", "vboxsf-3" },
    { "/sys/class/bdi/", "vboxsf-4" },
    { "/sys/class/bdi/", "vboxsf-5" },
    { "/sys/class/bdi/", "vboxsf-6" },
    { "/sys/class/misc/", "vboxuser" },
    { "/sys/class/misc/", "vboxguest" },
    { "/sys/module/", "vboxsf" },
    { "/sys/module/", "vboxguest" },
    { "/sys/module/vboxguest/drivers/", "pci:vboxguest" },
    { "/proc/irq/20/", "vboxguest" },
    { "/dev/", "vboxuser" },
    { "/dev/", "vboxguest" },
    { "/sys/kernel/debug/bdi/", "vboxsf-4" },
    { "/sys/kernel/debug/bdi/", "vboxsf-3" },
    { "/sys/kernel/debug/bdi/", "vboxsf-2" },
    { "/sys/kernel/debug/bdi/", "vboxsf-1" },
    { "/sys/module/vboxguest/holders/", "vboxsf" },
    { "/boot/bstmods/", "vboxguest.ko" },
    { "/boot/bstmods/", "vboxsf.ko" },
    { "/system/bin/", "microvirt-vbox-sf" },
    { "/system/bin/", "ttVM-vbox-sf" },
    { "/system/lib/", "vboxpcismv.ko" },
    { "/sys/bus/pci/drivers/", "vboxpciv" },
    { "/sys/bus/pci/drivers/", "vboxpci" },
    { "/sys/devices/virtual/misc/", "vboxpciv" },
    { "/sys/devices/virtual/misc/", "vboxpci" },
    { "/sys/class/misc/", "vboxpciv" },
    { "/sys/class/misc/", "vboxpci" },
    { "/sys/module/", "vboxpcismv" },
    { "/sys/module/vboxpcismv/drivers/", "pci:vboxpciv" },
    { "/dev/", "vboxpciv" },
    { "/dev/", "vboxpci" },
    { "/system/bin/", "mount.nemusf" },
    { "/system/bin/", "nemuVM-nemu-control" },
    { "/system/bin/", "nemuVM-nemu-service" },
    { "/system/bin/", "nemuVM-nemu-sf" },
    { "/system/bin/", "nemuVM-prop" },
    { "/system/lib/", "nemuguest.ko" },
    { "/system/lib/", "nemusf.ko" },
    { "/system/lib/", "nemuvideo.ko" },
    { "/system/usr/idc/nemuVM/Virtual/", "Input.idc" },
    { "/system/usr/keylayout/nemuVM/Virtual/", "Input.kl" },
    { "/sys/bus/pci/drivers/", "nemuguest" },
    { "/sys/devices/virtual/misc/", "nemuguest" },
    { "/sys/devices/virtual/misc/", "nemuuser" },
    { "/sys/class/misc/", "nemuguest" },
    { "/sys/class/misc/", "nemuuser" },
    { "/sys/module/", "nemuguest" },
    { "/sys/module/nemuguest/drivers/", "pci:nemuguest" },
    { "/sys/module/", "nemuvideo" },
    { "/sys/module/", "nemusf" },
    { "/proc/irq/20/", "nemuguest" },
    { "/data/data/com.netease.nemu/android/", "launcher.nemu" },
    { "/data/data/com.netease.nemu/vapi/", "android.nemu" },
    { "/data/data/com.netease.nemu/", "vinput.nemu" },
    { "/dev/", "nemuuser" },
    { "/dev/", "nemuguest" },
    { "/sys/bus/platform/devices/qemu/", "pipe" },
    { "/sys/bus/platform/drivers/qemu/", "pipe" },
    { "/sys/bus/platform/drivers/qemu/pipe/qemu/", "pipe" },
    { "/sys/bus/platform/drivers/qemu/", "trace" },
    { "/sys/devices/virtual/misc/qemu/", "pipe" },
    { "/sys/devices/platform/qemu/", "pipe" },
    { "/sys/class/misc/qemu/", "pipe" },
    { "/sys/qemu/", "trace" },
    { "/dev/qemu/", "pipe" },
    { "/data/downloads/", "bluestacksServices1.apk" },
    { "/data/downloads/", "51service.apk" },
    { "/system/bin/", "androVM-vbox-sf" },
    { "/system/lib/hw/", "audio.primary.vbox86.so" },
    { "/system/lib/hw/", "camera.vbox86.so" },
    { "/system/lib/hw/", "gps.vbox86.so" },
    { "/system/lib/hw/", "gralloc.vbox86.so" },
    { "/system/lib/hw/", "sensors.vbox86.so" },
    { "/system/lib/", "vboxvideo.ko" },
    { "/sys/module/", "vboxvideo" },
    { "/", "ueventd.andy.rc" },
    { "/system/priv-app/", "com.bluestacks.settings.apk" },
    { "/system/priv-app/", "com.bluestacks.BstCommandProcessor.apk" },
    { "/system/priv-app/", "com.bluestacks.bstfolder.apk" }
};

static SYSCALL_FUNCTION g_syscall_function;

static OPEN_FUNCTION g_open_function;

static CLOSE_FUNCTION g_close_function;

void vsfnnnnedn() {
    void *handle = dlopen("libc.so", RTLD_LAZY);
    g_syscall_function = (SYSCALL_FUNCTION)dlsym(handle, "syscall");
    g_open_function = (OPEN_FUNCTION)dlsym(handle, "open");
    g_close_function = (CLOSE_FUNCTION)dlsym(handle, "close");
    dlclose(handle);
}

int mmghsshshhs_cdcd() {
    int result = 0;
    int count = sizeof (g_characteristic_file_location_set) / sizeof (g_characteristic_file_location_set[0]);
    for (int i = 0; i < count; i++) {
        int directory_fd = g_open_function(g_characteristic_file_location_set[i].directory, O_DIRECTORY);
        if (directory_fd != -1) {
            int file_fd = g_syscall_function(322, directory_fd, g_characteristic_file_location_set[i].file, O_RDONLY);
            if (file_fd != -1) {
                result = -1;
                g_close_function(file_fd);
                break;
            }
            g_close_function(directory_fd);
        } // if (directory_fd != -1) {
    } // for (int i = 0; i < count; i++) {
        
    return result;
}

int __cxa_guard_acpulre() {
    // Initialize
    vsfnnnnedn();
    
    // Check characteristic file
    return mmghsshshhs_cdcd();
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

int cskckkavavavar() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            int fd = open("/system/lib/vboxvideo.ko", O_RDONLY);
            if (fd != -1) {
                close(fd);
            }
        }
    }
    
    return 0;
}

int cacnanknknkankcka() {
    vandvsvdvsvsknv();
    vandvsvdvsvsknv_cs();
    vandvsvdvsvsknv1();
    return 0;
}

void vandvsvdvsvsknv() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            int fd = open("/system/lib/vboxvideo.ko", O_RDONLY);
            if (fd != -1) {
                close(fd);
            }
        }
    }
}

void vandvsvdvsvsknv_cs() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            int fd = open("/system/lib/vboxvideo.ko", O_RDONLY);
            if (fd != -1) {
                close(fd);
            }
        }
    }
}

void vandvsvdvsvsknv1() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            int fd = open("/system/lib/vboxvideo.ko", O_RDONLY);
            if (fd != -1) {
                close(fd);
            }
        }
    }
}

void vandvsvdvsvsknv_2() {
    void *handle = dlopen("libc.so", RTLD_LAZY);
    if ((int)handle != -1) {
        dlclose(handle);
    }
}

void vandvsvdvsvskncascdv() {
    void *handle = dlopen("libc.so", RTLD_LAZY);
    if ((int)handle != -1) {
        dlclose(handle);
    }
}

void vandvsvcsadcdvsvsknv() {
    void *handle = dlopen("libc.so", RTLD_LAZY);
    if ((int)handle != -1) {
        dlclose(handle);
    }
}

void vandvsvdvscdsavsknv() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            int fd = open("/system/lib/vboxvideo.ko", O_RDONLY);
            if (fd != -1) {
                close(fd);
            }
        }
    }
}

void vandvscsdcscvdvsvsknv() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            int fd = open("/system/lib/vboxvideo.ko", O_RDONLY);
            if (fd != -1) {
                close(fd);
            }
        }
    }
}

void wrgvandvsvdvsvsknv() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            int fd = open("/system/lib/vboxvideo.ko", O_RDONLY);
            if (fd != -1) {
                close(fd);
            }
        }
    }
}

void vandvsvdvs12vsknv() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            int fd = open("/system/lib/vboxvideo.ko", O_RDONLY);
            if (fd != -1) {
                close(fd);
            }
        }
    }
}

int vand34vsvdvsvsknv() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            int fd = open("/system/lib/vboxvideo.ko", O_RDONLY);
            if (fd != -1) {
                close(fd);
            }
        }
    }
    
    return 0;
}

void vandvsvdv45svsknv() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            int fd = open("/system/lib/vboxvideo.ko", O_RDONLY);
            if (fd != -1) {
                close(fd);
            }
        }
    }
}

void vandvsvdv54svsknv() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            int fd = open("/system/lib/vboxvideo.ko", O_RDONLY);
            if (fd != -1) {
                close(fd);
            }
        }
    }
}

void vand234vsvdvsvsknv() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            int fd = open("/system/lib/vboxvideo.ko", O_RDONLY);
            if (fd != -1) {
                close(fd);
            }
        }
    }
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
