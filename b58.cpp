#include "b58.h"


// PrivateKey_To_WIF_Comp("13d7ac1435681dacca23bb............638276723");
// PrivateKey_To_WIF_Comp(6543456789238765................456738292308786751324542);
// PrivateKey_To_WIF("13d7ac1435681dacca23bb............638276723");
// PrivateKey_To_WIF(6543456789238765................456738292308786751324542);
// PrivateKey_To_WIF_Comp();
// PrivateKey_To_WIF_Comp();


int main(int argc, char const *argv[])
{
	string c = "123456789", v = "BukQL";
	string data = ENCODE(c, false); // false for non hexadecimal, true for hexadecimal input
	cout << c << " = " << data << "\n\n";

	string x = DECODE(data, false); // false for decimal output, true for hexadecimal conversion
	cout << data << " = " << x << "\n\n";

	return 0;
}
