#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <string>
#include <map>
#include <utility>
#include <regex>

using namespace std;

map<string, string> morseTable = {
	{".-","A"},
	{"-...","B"},
	{"-.-.","C"},
	{"-..","D"},
	{".","E"},
	{".._.","F"},
	{"--.","G"},
	{"....","H"},
	{"..","I"},
	{".---","J"},
	{"-.-","K"},
	{"._..","L"},
	{"--","M"},
	{"-.","N"},
	{"---","O"},
	{".--.","P"},
	{"--.-","Q"},
	{".-.","R"},
	{"...","S"},
	{"-","T"},
	{"..-","U"},
	{"...-","V"},
	{".--","W"},
	{"-..-","X"},
	{"-.--","Y"},
	{"--..","Z"},
	{".----","1"},
	{"..---","2"},
	{"...--","3"},
	{"....-","4"},
	{".....","5"},
	{"-....","6"},
	{"-...","7"},
	{"-..","8"},
	{"-.","9"},
	{"-","0"},
	{";"," "}
};

string decode(string input)
{
        string decoded;
        //Step 1: Split by spaces
	regex spaces("   *");
	string result;
        regex_replace(back_inserter(result), input.begin(), input.end(), spaces, " ; ");
	
	istringstream iss(result);   //string stream produces strings up to next space!
	vector<string> splited((istream_iterator<string>(iss)),istream_iterator<string>());




	for (auto element : splited)
	{
		decoded += morseTable[element];
	}

        return decoded;
}

int main(void)
{       
        cout << "Morse decoder - Kata" << endl;
        string dataToDecode;
        cout << "Type morse code string: " ;
        getline(cin, dataToDecode);
        cout << endl << endl << "Decoded string: " << decode(dataToDecode);
}       

