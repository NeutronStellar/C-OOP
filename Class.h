#ifndef Class_h
#define Class_h

typedef struct Class {
	size_t size;
	const struct Class *super;
	unsigned (*hash)(const void *);
	int (*cmp)(const void *, const void *);
	void *(*dup)(const void *);
	void *init;
} Class;
typedef struct Object {
	const struct Class *class;
} Object;
extern const Class ObjectClass;
int instanceof(const void *, const void *), Object_cmp(const void *, const void *);
unsigned Object_hash(const void *);
void *Object_dup(const void *), Object_init(void *);

#endif /* Class_h */