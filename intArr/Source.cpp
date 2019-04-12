#include "vectors_.h"

void main()
{
	vectors_ a(1, 5);
	vectors_ b(3, 5);
	a.print();
	b.print();
	b = a;
	b.print();

	system("pause");
}
