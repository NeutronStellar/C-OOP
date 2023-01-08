#include <stdlib.h>
#include <string.h>
#include "Class.h"
const Class ObjectClass = {sizeof(Class), NULL, Object_hash, Object_cmp, Object_dup, Object_init};
void Object_init(void *const obj) {
	((Object *)obj)->class = &ObjectClass;
}
unsigned Object_hash(const void *const obj) {
	return ((Object *)obj)->class->size;
}
int Object_cmp(const void *const obj0, const void *const obj1) {
	return memcmp(obj0, obj1, ((Object *)obj0)->class->size);
}
void *Object_dup(const void *const obj) {
	const size_t size = ((Object *)obj)->class->size;
	return memcpy(malloc(size), obj, size);
}
int instanceof(const void *obj, const void *const class) {
	obj = ((Object *)obj)->class;
	do {
		if (obj == class)
			return 1;
	} while ((obj = ((Class *)obj)->super));
	return 0;
}
