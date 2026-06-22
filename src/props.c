#include "props.h"

#include <objc/message.h>

#include "function.h"

id prop_get_obj(id outer_obj, const char* prop_name) {
	return ((getter_obj)objc_msgSend)(
		outer_obj,
		sel_registerName(prop_name)
	);
}

long prop_get_long(id outer_obj, const char* prop_name) {
	return ((getter_long)objc_msgSend)(
		outer_obj,
		sel_registerName(prop_name)
	);
}

BOOL prop_get_bool(id outer_obj, const char* prop_name) {
	return ((getter_bool)objc_msgSend)(
		outer_obj,
		sel_registerName(prop_name)
	);
}
