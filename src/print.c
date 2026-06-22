#include "print.h"

#include <objc/objc.h>
#include <objc/runtime.h>
#include <os/log.h>

os_log_t app_log;
void log_init() {
	app_log = os_log_create("69", "");
}

void print_s(const char* str) {
#if TARGET_OS_IPHONE
	os_log(app_log, "%s", str);
#else
	puts(str);
#endif
}

void print_u32(uint32_t number) {
#if TARGET_OS_IPHONE
	os_log(app_log, "%d", number);
#else
	printf("%d\n", number);
#endif
}

void print_class(Class class) {
#if TARGET_OS_IPHONE
	os_log(app_log, "%s - %p", class_getName(class), class);
#else
	printf("%s - %p\n", class_getName(class), class);
#endif
}

void print_ptr(void* ptr) {
#if TARGET_OS_IPHONE
	os_log(app_log, "%p", ptr);
#else
	printf("%p\n", ptr);
#endif
}

void print_args(const int argc, char** argv) {
	char arg_count[32];
	snprintf(arg_count, 32, "argc: %d", argc);
	print_s(arg_count);

	for (int i = 0; i < argc; ++i) {
		print_s(argv[i]);
	}
}

void print_banner() {
	print_s("");
	print_s("");
	print_s("|_________________|");
	print_s("|------START------|");
	print_s("|-----------------|");
}