#include <stdio.h>
#include <pwd.h>

//struct passwd * getpwnam(const char *name)
//{
//	struct passwd *ptr;
//
//	setpwent();
//	while ((ptr = getpwent()) !== NULL) {
//		if (strcmp(name, ptr->pw_name) == 0) {
//			break;	
//		}
//	}
//
//	endpwent();
//	return ptr;
//}
//
int main(void)
{
	struct passwd *swan;
	setpwent();
	while ((swan = getpwent()) != NULL) {
		printf("system user: %s\n", swan->pw_name);
	}

	endpwent();
	return 0;	
}
