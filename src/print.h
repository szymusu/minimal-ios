#ifndef MINIMAL_IOS_PRINT_H
#define MINIMAL_IOS_PRINT_H

#include <objc/objc.h>

void log_init();
void print_s(const char* str);
void print_u32(uint32_t number);
void print_bool(bool value);
void print_class(Class class);
void print_ptr(void* ptr);
void print_args(int argc, char** argv);
void print_banner();

#endif //MINIMAL_IOS_PRINT_H
