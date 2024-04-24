#include "algoritm.h"

void rem(auto* arr, auto* remel)
{
	(*arr).erase(remove((*arr).begin(), (*arr).end(), (*remel)), (*arr).end());
}
