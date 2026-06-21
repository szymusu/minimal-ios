#include "print.h"

#include <objc/objc.h>
#include <objc/runtime.h>
#include <os/log.h>


void print_s(const char* str) {
#if TARGET_OS_IPHONE
	os_log(OS_LOG_DEFAULT, "%s", str);
#else
	puts(str);
#endif
}

void print_class(Class class) {
#if TARGET_OS_IPHONE
	os_log(OS_LOG_DEFAULT, "%s - %p", class_getName(class), class);
#else
	printf("%s - %p\n", class_getName(class), class);
#endif
}

void print_ptr(void* ptr) {
#if TARGET_OS_IPHONE
	os_log(OS_LOG_DEFAULT, "%p", ptr);
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