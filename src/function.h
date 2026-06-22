#ifndef MINIMAL_IOS_FUNCTION_H
#define MINIMAL_IOS_FUNCTION_H

#include <objc/objc.h>

typedef id	 (*func_noArgs_obj)	(id, SEL);
typedef long (*func_noArgs_long)(id, SEL);
typedef BOOL (*func_noArgs_bool)(id, SEL);

typedef func_noArgs_obj getter_obj;
typedef func_noArgs_long getter_long;
typedef func_noArgs_bool getter_bool;

#endif //MINIMAL_IOS_FUNCTION_H
