#include <stdio.h>
#include <stdarg.h>

//#define DEBUG 

#ifdef DEBUG
void mprintf(char *buf, ...)
{
	va_list ap;
	va_start(ap, buf);
	vprintf(buf, ap);
	va_end(ap);
}
#else
void mprintf(char *buf, ...){}
#endif


int main()
{
	mprintf("Hello World\n");
}
