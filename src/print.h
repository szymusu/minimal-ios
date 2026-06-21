#ifndef MINIMAL_IOS_PRINT_H
#define MINIMAL_IOS_PRINT_H

#include <objc/objc.h>

void print_s(const char* str);
void print_class(Class class);
void print_ptr(void* ptr);
void print_args(int argc, char** argv);

#endif //MINIMAL_IOS_PRINT_H
