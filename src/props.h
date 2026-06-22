#ifndef MINIMAL_IOS_PROPS_H
#define MINIMAL_IOS_PROPS_H
#include <objc/objc.h>

id prop_get_obj(id outer_obj, const char* prop_name);
long prop_get_long(id outer_obj, const char* prop_name);
BOOL prop_get_bool(id outer_obj, const char* prop_name);

#endif //MINIMAL_IOS_PROPS_H
