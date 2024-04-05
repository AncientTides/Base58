#ifndef B58_H
#define B58_H

#include "bin_con.h"
#include <cmath>

using std::cout; using std::string; using std::vector; using std::stringstream;

string base58Transponder(int value);
string AsciiToDec_(string workload);
string ENCODE(string data, bool f);
string DECODE(string base58, bool f);
BigInteger POWER_8_e(BigInteger base, BigInteger constant, int exponent);



int BigInteger2String_To_Integer(BigInteger j)
{
	stringstream jj;
	int g;
	jj << j;
	jj >> g;
	jj.clear();
	return g;
}


BigInteger POWER_8_e(BigInteger base, BigInteger constant, int exponent)
{
	BigInteger result = constant;
	for (int i = 0; i < exponent; ++i)
		result = result * constant;
	result = base * result/constant;
	return result;
} // CORRECT ---04:22 PM 31/10/2022


string base58Transponder(int value)
{
	vector <string> base_elements = {"1","2","3","4","5","6","7","8","9","A","B","C","D","E","F","G","H","J","K","L","M","N","P","Q","R","S","T","U","V","W","X","Y","Z","a","b","c","d","e","f","g","h","i","j","k","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};// All alphanumeric characters except for "0", "I", "O", and "l"
	string sx = base_elements[value];
	if(value > 57)
		throw "ERROR !! VALUE PAIR NON EXISTENT IN ALLOWED ALPHANUMERIC LETTERS";
	else
		return sx;
} // 03:27AM 10/10/2022


string AsciiToDec_(char workload)
{
	string fff = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz", s;
	// vector<int> lib = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
	for(int x = 0; x < fff.length(); x++) // get decimal value of ascii values
		if (workload == fff[x])
			return Int2String(x); // return decimal value in equivalent lib vector index
	return s;
} 


string ENCODE(string data, bool f)
{
	int k = 0;
	string cdx;
	BigInteger a, b(58), c;

	if (f==true)
		a = Hex_To_BigNum(data);
	else
		a = String_2_BigInteger(data);

	while(true)
	{
		c = a % b; // calculate remainder value
		k = BigInteger2String_To_Integer(c); // convert remainder to int
		cdx += base58Transponder(k);
	    a = a / b; // decrement a
	    if(a==0)
	    	break;
	}
	return ReverseString(cdx);
} // 31/10/22 08:33 AM


string DECODE(string base58, bool f)
{
	string gx, ww;
	int k = 0, j = base58.length()-1;
	// cout << "size of decode string = " << j << "\n";
	BigInteger a, b(58), c, d;	
	
	for(int p = 0; p < base58.length(); p++)
	{
		ww = AsciiToDec_(base58[p]); // get ascii decimal value of index p
		a = String_2_BigInteger(ww); // convert string to BigInteger
		c = POWER_8_e(a, b, j);
		d += c; // sum all exponents of c
		// cout << d << "\n"; // DEBUGGING PURPOSE ONLY!!
		j-=1;
	}

	if (f == true) // hex return flag is true, return value as hexadecimal
		gx = IntegerToHex(d);
	else // else return as numeric string
		gx = BigInteger2String(d);

	return gx;
}





#endif // B58_H
/*
// USAGE

PrivateKey_To_WIF_Comp("13d7ac1435681dacca23bb............638276723");
PrivateKey_To_WIF_Comp(6543456789238765................456738292308786751324542);
PrivateKey_To_WIF("13d7ac1435681dacca23bb............638276723");
PrivateKey_To_WIF(6543456789238765................456738292308786751324542);
PrivateKey_To_WIF_Comp();
PrivateKey_To_WIF_Comp();


int main(int argc, char const *argv[])
{
	string c = "123456789", v = "BukQL";
	string data = ENCODE(c, false); // false for non hexadecimal, true for hexadecimal input
	cout << c << " = " << data << "\n\n";

	string x = DECODE(data, false); // false for decimal output, true for hexadecimal conversion
	cout << data << " = " << x << "\n\n";

	return 0;
}
*/