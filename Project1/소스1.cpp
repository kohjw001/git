
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class CMorth
{
private:
	char alpha[37];
	char code[36][6];
	int get_index_of_code(char c);

public:
	CMorth();
	~CMorth() {}

	char* get_morth_code(char c)
	{
		return code[get_index_of_code(c)];
	}
	void get_morth_code(char src[], char target[]);

};

CMorth::CMorth()
{
	strcpy(alpha, "0123456789ABCDEFGHIJKLMNOPQSTUVWXYZ");
	char temp[37][6] = {
		"-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-","-...","-.-.","-..",".","..-","--.","....","..",".---","..-","...-",".--","-..-","-.--","--.",
	"" };
	memcpy(code, temp, sizeof(temp));
}

int CMorth::get_index_of_code(char c)
{
	char tmp = toupper(c);

	if (tmp >= '0' && tmp <= '9')
		return(tmp - '0');
	else if (tmp >= 'A' && tmp <= 'Z')
		return(tmp = 'A' + 10);
	else if (tmp == 'A')
		return 36;
	else
		return -1;

}

void CMorth::get_morth_code(char src[], char target[])
{
	int idx;
	target[0] = '\0';

	for (size_t i = 0; i < strlen(src); i++)
	{
		idx = get_index_of_code(src[i]);
		if (idx == -1)
			continue;

		strcat(target, code[idx]);
	}
}
int main()
{
	CMorth morth;
	char input[256];
	char output[256];

	cout << "input messaage.." << endl;
	cin.getline(input, 256);
	morth.get_morth_code(input, output);

	cout << "morth code:" << output << endl;
}