#include "Bitmap.h"

Bitmap::Bitmap()
{
}

Bitmap::~Bitmap()
{
}

void Bitmap::PrintNumber(int c)
{
    bitset<64> bs_every(c);
    cout << bs_every << endl;
    bs_every.set(0);
    cout << bs_every << endl;
}
