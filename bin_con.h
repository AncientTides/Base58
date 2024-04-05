#ifndef BIN_CON_H
#define BIN_CON_H


#include <iostream> // Include iostream header file
#include <vector> // Include vector header file
#include <string> // Include string header file
#include <sstream> // Include sstream header file
#include "bignum_def.h" // BigInteger


using std::cout; // enables you to call as "cout" instead of "std::cout"
using std::string; // enables you to call as "string" instead of "std::string"
using std::stringstream; // enables you to call as "stringstream" instead of "std::stringstream"
using std::vector; // enables you to call as "vector" instead of "std::vector"


string BigToLittleAlphabets(string data); // convert upper-case hex values to lower-case letters
string int2String(uint32_t value); // Convert a uint32_t decimal value to a string
string filter(string data); // Get rid of excess raw bytes due to out-of-range element access
string decimalToBinary(uint32_t num); // Convert a uint32_t decimal value to binary string
uint32_t stringToDecimal(string c); // Convert a string decimal value to uint32_t value
uint32_t charToDecimal(char c); // Convert a single char decimal value to uint32_t value
uint32_t power(uint32_t n, uint32_t e); // Calculate the exponent of given decimal value| power(2,4)=16
uint32_t binaryToDecimal(string bin); // Convert binary string to uint32_t decimal number
uint32_t hex2dec(string hex_v); // Convert hexadecimal values to uint32_t
string hexToBinary(string data); // Convert hex or decimal data to binary
string Swap_2bits(string data); // SWAP ENDAINESS
vector<unsigned char> hex2bytes(const string& s);


string BigInteger2String(BigInteger value); // Convert a BigInteger value to a string
BigInteger filter(BigInteger data); // Get rid of excess raw bytes due to out-of-range element access
BigInteger String_2_BigInteger(string value); // Convert a string decimal value to BigInteger value
BigUnsigned String_2_BigUnsigned(string value); // Convert a string decimal value to BigInteger value
BigInteger DecimalToBinary__BigInteger(BigInteger num); // Convert BigInteger decimal to binary strings
string DecimalToBinary_String(BigInteger num); // Convert BigInteger decimal to binary strings
BigInteger BigInteger_charToDecimal(char c); // Convert a single char decimal value to BigInteger value
BigInteger BigInteger_power(BigInteger n, BigInteger e); // Calculate the exponent of given BigInteger value| power(2,4)=16
BigInteger BigInteger_binaryToDecimal(BigInteger bin); // Convert binary string to BigInteger number
BigInteger Hex_To_BigNum(string hex_v); // Convert hexadecimal values to BigInteger
string IntegerToHex(BigInteger num); // convert BigInteger value to hexadecimal strings
string UNSIGNED_IntegerToHex(BigUnsigned num);  // convert BigInteger value to hexadecimal strings
BigInteger BigInteger_binary_2_Decimal(string bo);
string stringToHex(string data){ return IntegerToHex(String_2_BigInteger(data));}
string stringToHex_U(string data){ return UNSIGNED_IntegerToHex(String_2_BigUnsigned(data));}
// DEFINITIONS


string ReverseString(string data)
{
	string data_var;
	int count;
	count = data.length()-1;
	while (count >= 0)
	{
		data_var = data_var + data[count];
		count--;
	}
	return data_var;
}


string Swap_2bits(string data) // SWAP ENDAINESS
{
    vector<string> t1;
    string bits; // global return variable

    for (int i = 0; i < data.length()+2; i+=2)
        t1.push_back(data.substr(i, 2));

    for (int b = 0; b < t1.size()+1; ++b)
        bits += t1[t1.size()-b];
    return bits;
}



vector<unsigned char> hex2bytes(const string& s)
{
    constexpr size_t width = sizeof(unsigned char) * 2;
    std::vector<unsigned char> v;
    v.reserve((s.size() + width - 1) / width);
    for (auto it = s.crbegin(); it < s.crend(); it += width)
    {
        auto begin = std::min(s.crend(), it + width).base();
        auto end = it.base();
        std::string slice(begin, end);
        unsigned char value = std::stoul(slice, 0, 16);
        v.push_back(value);
    }
    return v;
}



string BigToLittleAlphabets(string data)
{
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == 'A')
			data[i] = 'a';
		if (data[i] == 'B')
			data[i] = 'b';
		if (data[i] == 'C')
			data[i] = 'c';
		if (data[i] == 'D')
			data[i] = 'd';
		if (data[i] == 'E')
			data[i] = 'e';
		if (data[i] == 'F')
			data[i] = 'f';
	}
	return data;
}


string int2String(uint32_t value)
{
	string dd; // string variable declaration
	stringstream ss; // stream object initialization
	ss << value; // stream data into object
	ss >> dd; // stream data into string variable
	ss.clear(); // clear stream object
	return dd; // return value
}



string Int2String(int value)
{
	string dd; // string variable declaration
	stringstream ss; // stream object initialization
	ss << value; // stream data into object
	ss >> dd; // stream data into string variable
	ss.clear(); // clear stream object
	return dd; // return value
}

string BigInteger2String(BigInteger value)
{
	string dd; // string variable declaration
	stringstream ss; // stream object initialization
	ss << value; // stream data into object
	ss >> dd; // stream data into string variable
	ss.clear(); // clear stream object
	return dd; // return value
}


string BigUnsigned2String(BigUnsigned value)
{
	string dd; // string variable declaration
	stringstream ss; // stream object initialization
	ss << value; // stream data into object
	ss >> dd; // stream data into string variable
	ss.clear(); // clear stream object
	return dd; // return value
}


BigInteger String_2_BigInteger(string value)
{
	BigInteger dd = stringToBigInteger(value); // BigInteger variable declaration
	return dd; // return value
}

BigUnsigned String_2_BigUnsigned(string value)
{
	BigUnsigned dd = stringToBigUnsigned(value); // BigInteger variable declaration
	return dd; // return value
}

string filter(string data)
{
	string bits; // declare string variable
	uint32_t fp = data.length(); // declare uint32_t variable and set value to length of data
	for (uint32_t i = 0; i < data.length(); ++i) // for every elements within string data
	{
		bits+= data.substr(fp, 1); // concatenate values after STL string function processing of 1 char
		fp-=1; // decrement fp value
	}
	return bits; // return value
}

BigInteger filter(BigInteger data)
{
	string bits, von = BigInteger2String(data); // declare string variable
	uint32_t fp = von.length(); // declare uint32_t variable and set value to length of data
	for (uint32_t i = 0; i < von.length(); ++i) // for every elements within string data
	{
		bits+= von.substr(fp, 1); // concatenate values after STL string function processing of 1 char
		fp-=1; // decrement fp value
	}
	data = String_2_BigInteger(bits); // convert string to BigInteger
	return data; // return value
}

string decimalToBinary(uint32_t num)
{
	uint32_t n; // declare uint32_t decimal variable
	string bin, temp; // declare string variables
	while(num != 0) // while num is not equal to 0
	{
		n = num % 2; // mod value by 2 and store remainder
	    num = num / 2; // divide by 2
	    temp += int2String(n); // convert to string and concatenate within string
	}
	for (uint32_t i = 0; i < temp.length()+1; ++i) // for every element within temp variable
		bin += temp[temp.length()-i]; // sum together all values starting from the last to first
	bin = filter(bin); // filter value due to excess out-of-range index access
	return bin; // return value
}


BigInteger DecimalToBinary__BigInteger(BigInteger num)
{
	BigInteger n; // declare BigInteger variable
	string bin, temp; // declare string variables
	while(num != 0) // while num is not equal to 0
	{
		n = num % 2; // mod value by 2 and store remainder
	    num = num / 2; // divide by 2
	    temp += BigInteger2String(n); // convert to string and concatenate within string
	}
	for (uint32_t i = 0; i < temp.length()+1; ++i) // for every element within temp variable
		bin += temp[temp.length()-i]; // sum together all values starting from the last to first
	bin = filter(bin); // filter value due to excess out-of-range index access
	n = String_2_BigInteger(bin); // MIGHT DISCARD LEADING ZERO...!!
	return n; // return value
}



string DecimalToBinary_String(BigInteger num)
{
	BigInteger n, div = 2; // declare BigInteger variable
	string bin, temp; // declare string variables
	while(num != 0) // while num is not equal to 0
	{
		n = num % div; // mod value by 2 and store remainder
	    num = num / div; // divide by 2
	    temp += BigInteger2String(n); // convert to string and concatenate within string
	}
	int lenf = temp.length();
	for (int i = 0; i < temp.length(); ++i) // for every element within temp variable
	{
		bin += temp[lenf-i]; // sum together all values starting from the last to first
		if (i == temp.length()-1)
 			bin += temp[0];
	}
	bin = filter(bin); // filter value due to excess out-of-range index access
	return bin; // return value
}




string DecimalToBinary(BigInteger num)
{
	vector<BigInteger> temp;
	BigInteger n, div = 2; // declare BigInteger variable
	string bin = "";//, temp; // declare string variables
	while(num > 0) // while num is not equal to 0
	{
		n = num % div; // mod value by 2 and store remainder
	    num = num / div; // divide by 2 yo update but simultaneously decrease num
	    // temp += BigInteger2String(n); // convert to string and concatenate within string
	    temp.push_back(n);
	}

	for (int i = temp.size()-1; i >= 0; i--)
	{
		n = temp[i];
		bin += bigIntegerToString(n);
	}
	return bin; // return value
}



string DecimalToBinary_Backwards(BigInteger num)
{
	BigInteger n, div = 2; // declare BigInteger variable
	string bin = "", temp; // declare string variables
	while(num > 0) // while num is not equal to 0
	{
		n = num % div; // mod value by 2 and store remainder
	    num = num / div; // divide by 2 yo update but simultaneously decrease num
	    temp += BigInteger2String(n); // convert to string and concatenate within string
	}
	return temp; // return value
}

string UNSIGNED_DecimalToBinary_Backwards(BigUnsigned num)
{
	BigUnsigned n, div = 2; // declare BigUnsigned variable
	string bin = "", temp; // declare string variables
	while(num > 0) // while num is not equal to 0
	{
		n = num % div; // mod value by 2 and store remainder
	    num = num / div; // divide by 2 yo update but simultaneously decrease num
	    temp += BigUnsigned2String(n); // convert to string and concatenate within string
	}
	return temp; // return value
}


uint32_t stringToDecimal(string c)
{
	uint32_t dx; // uint32_t decimal variable declaration
	stringstream kk; // stream object initialization
	kk << c; // stream data into object
	kk >> dx; // stream data into uint32_t decimal variable
	kk.clear(); // clear stream object
	return dx; // return value
}

int String_2_Int(string c)
{
	int dx; // uint32_t decimal variable declaration
	stringstream kk; // stream object initialization
	kk << c; // stream data into object
	kk >> dx; // stream data into uint32_t decimal variable
	kk.clear(); // clear stream object
	return dx; // return value
}

uint32_t charToDecimal(char c)
{
	uint32_t dx; // uint32_t decimal variable declaration
	stringstream kk; // stream object initialization
	kk << c; // stream data into object
	kk >> dx; // stream data into uint32_t decimal variable
	kk.clear(); // clear stream object
	return dx; // return value
}


BigInteger BigInteger_charToDecimal(char c)
{
	BigInteger dx; // BigInteger variable declaration
	int g;
	stringstream kk; // stream object initialization
	kk << c; // stream data into object
	kk >> g; // stream data into BigInteger variable
	kk.clear(); // clear stream object
	dx = g;
	return dx; // return value
}

uint32_t power(uint32_t n, uint32_t e)
{
	uint32_t x = n; // declare uint32_t decimal variable and assign the value of base number to it
	if (e == 0) // if exponent value is 0
		return n; // No need for loop, return 1
	if (n == 0) // if base value is 0
		return 1; // No need for loop, return 0

	for (uint32_t b = 1; b < e; b++) // for exponent value starting from an offset of 1
		n = n*x; // base value * base value
	return n; // return value
}


BigInteger BigInteger_power(BigInteger n, BigInteger e)
{
	BigInteger x = n; // declare uint32_t decimal variable and assign the value of base number to it
	if (e == 0) // if exponent value is 0
		return n; // No need for loop, return 1
	if (n == 0) // if base value is 0
		return 1; // No need for loop, return 0

	for (BigInteger b = 1; b < e; b++) // for exponent value starting from an offset of 1
		n = n*x; // base value * base value
	return n; // return value
}

uint32_t binaryToDecimal(string bin)
{
	uint32_t dec = 0, zap = 0, e = 2; // declare uint32_t decimal variables and assign default values
	for (uint32_t i = 1; i < bin.length()+1; ++i) // for number of elemets within string, offset of 1
	{
		zap = charToDecimal(bin[bin.length()-i]) * power(e, i); // binary value * 2^i
		dec += zap; // add values together
	}
	return dec/2; // return value after dividing by 2. Due to offset
}

BigInteger BigInteger_binaryToDecimal(BigInteger bin)
{
	string bo = BigInteger2String(bin); // declare string, convert BigInteger value and store within string
	BigInteger dec = 0, zap = 0, e = 2; // declare uint32_t decimal variables and assign default values
	for (uint32_t i = 1; i < bo.length()+1; ++i) // for number of elemets within string, offset of 1
	{
		zap = BigInteger_charToDecimal(bo[bo.length()-i]) * BigInteger_power(e, i); // binary value * 2^i
		dec += zap; // add values together
	}
	return dec/2; // return value after dividing by 2. Due to offset
}

BigInteger BigInteger_binary_2_Decimal(string bo)
{
	BigInteger dec = 0, zap = 0, e = 2; // declare uint32_t decimal variables and assign default values
	for (uint32_t i = 1; i < bo.length()+1; ++i) // for number of elemets within string, offset of 1
	{
		zap = BigInteger_charToDecimal(bo[bo.length()-i]) * BigInteger_power(e, i); // binary value * 2^i
		dec += zap; // add values together
	}
	return dec/2; // return value after dividing by 2. Due to offset
}


uint32_t hex2dec(string hex_v)
{
	vector<uint32_t> bush;
	uint32_t num = 0;
	for (uint32_t o = 0, e = hex_v.length(); o < hex_v.length(); ++o, e--)
	{
		if (hex_v[o] == '0')
			num = 0;
		else if (hex_v[o] == '1')
			num = 1;
		else if (hex_v[o] == '2')
			num = 2;
		else if (hex_v[o] == '3')
			num = 3;
		else if (hex_v[o] == '4')
			num = 4;
		else if (hex_v[o] == '5')
			num = 5;
		else if (hex_v[o] == '6')
			num = 6;
		else if (hex_v[o] == '7')
			num = 7;
		else if (hex_v[o] == '8')
			num = 8;
		else if (hex_v[o] == '9')
			num = 9;
		else if ((hex_v[o] == 'a') || (hex_v[o] == 'A'))
			num = 10;
		else if ((hex_v[o] == 'b') || (hex_v[o] == 'B'))
			num = 11;
		else if ((hex_v[o] == 'c') || (hex_v[o] == 'C'))
			num = 12;
		else if ((hex_v[o] == 'd') || (hex_v[o] == 'D'))
			num = 13;
		else if ((hex_v[o] == 'e') || (hex_v[o] == 'E'))
			num = 14;
		else if ((hex_v[o] == 'f') || (hex_v[o] == 'F'))
			num = 15;

		num = num * power(16, e);
		bush.push_back(num);
	}
	num = 0;

	for (uint32_t y = 0; y < bush.size(); ++y)
		num += bush[y];

	return num/16;
}


BigInteger Hex_To_BigNum(string hex_v)
{
	BigInteger bigO;
	vector<BigInteger> bush;
	BigInteger num = 0;
	for (uint32_t o = 0, e = hex_v.length(); o < hex_v.length(); ++o, e--)
	{
		if (hex_v[o] == '0')
			num = 0;
		else if (hex_v[o] == '1')
			num = 1;
		else if (hex_v[o] == '2')
			num = 2;
		else if (hex_v[o] == '3')
			num = 3;
		else if (hex_v[o] == '4')
			num = 4;
		else if (hex_v[o] == '5')
			num = 5;
		else if (hex_v[o] == '6')
			num = 6;
		else if (hex_v[o] == '7')
			num = 7;
		else if (hex_v[o] == '8')
			num = 8;
		else if (hex_v[o] == '9')
			num = 9;
		else if ((hex_v[o] == 'a') || (hex_v[o] == 'A'))
			num = 10;
		else if ((hex_v[o] == 'b') || (hex_v[o] == 'B'))
			num = 11;
		else if ((hex_v[o] == 'c') || (hex_v[o] == 'C'))
			num = 12;
		else if ((hex_v[o] == 'd') || (hex_v[o] == 'D'))
			num = 13;
		else if ((hex_v[o] == 'e') || (hex_v[o] == 'E'))
			num = 14;
		else if ((hex_v[o] == 'f') || (hex_v[o] == 'F'))
			num = 15;

		num = num * BigInteger_power(16, e);
		bush.push_back(num);
	}
	num = 0;

	for (uint32_t y = 0; y < bush.size(); ++y)
		num += bush[y];// bigO = int_2_BigNum(num);
	
	return num/16;
	// return bigO/16;
}



string IntegerToHex(BigInteger num)
{
	vector<char> arr;
	string cache;
	int i = 0;
    if (num == 0)
    {
        stringstream cs;
        cs << num;
        cs >> cache;
        cs.clear();
        return cache;
    }
	while(num != 0) 
	{
		int temp = 0;
		temp = (num % 16).toUnsignedInt();
		if(temp < 10)
		{
			arr.push_back(temp + 48);
			i++;
		} 
		else 
		{
			arr.push_back(temp + 55);
			i++;
		}
		num = num/16;
	}
	for(int j = i-1; j >= 0; j--)
		cache += arr[j]; // cache+= arr[j];
	
	// ENSURE 64 character hexadecimal output
	if ((cache.length() < 65) && (cache.length() != 64))
	{
		int mz = 64 - cache.length();
		for (int i = 0; i < mz; ++i)
			cache = "0" + cache; // pad beginning of hex with 0 as it has no significant value to current hex value 
	}

	return BigToLittleAlphabets(cache);
	// return cache;
} // 03:50PM 18/09/2022





string UNSIGNED_IntegerToHex(BigUnsigned num)
{
	vector<char> arr;
	string cache;
	int i = 0;
    if (num == 0)
    {
        stringstream cs;
        cs << num;
        cs >> cache;
        cs.clear();
        return cache;
    }
	while(num != 0) 
	{
		int temp = 0;
		temp = (num % 16).toUnsignedInt();
		if(temp < 10)
		{
			arr.push_back(temp + 48);
			i++;
		} 
		else 
		{
			arr.push_back(temp + 55);
			i++;
		}
		num = num/16;
	}
	for(int j = i-1; j >= 0; j--)
		cache += arr[j]; // cache+= arr[j];

	return BigToLittleAlphabets(cache);
	// return cache;
} // 03:50PM 18/09/2022




string hexToBinary(string data)
{
	return DecimalToBinary_String(Hex_To_BigNum(data));
}






#endif // BIN_CON_H


