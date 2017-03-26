/*#include <fstream>
#include <iostream>
#include <string>

int main()
{
	std::ifstream ifs("Test.txt");
	char str[256];
	
	if (ifs.fail())
	{
		std::cerr << "���s" << std::endl;
		return -1;
	}
	while (ifs.getline(str, 256 - 1))
	{
		std::cout << str << std::endl;
	}
	
	
	return 0;
}
*/

#include<fstream>
#include<iostream>
#include<string>
#include<sstream> //�����X�g���[��
#include <iomanip>
using namespace std;
/*
int main(){

	//�t�@�C���̓ǂݍ���
	ifstream ifs("Test.csv");
	if (!ifs){
		cout << "���̓G���[";
		return 1;
	}

	//csv�t�@�C����1�s���ǂݍ���
	string str;

	while (getline(ifs, str)){
		string token;
		istringstream stream(str);

		//1�s�̂����A������ƃR���}�𕪊�����
		while (getline(stream, token, ',')){
			//���ׂĕ�����Ƃ��ēǂݍ��܂�邽��
			//���l�͕ϊ����K�v
			int temp = stof(token); //stof(string str) : string��float�ɕϊ�
			
			cout << temp << ", ";
		}
		cout << endl;
	}
	return 0;
}*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int count_j = -1;
int main(void)
{
	//�t�@�C���̓ǂݍ���
	ifstream fi("GPS.csv");
	int i;
	char c;
	double array[500][2];
	if (!fi) {
		cerr << "open error" << endl;
		return -1;
	}
	i = 0;
	while (i < 500) {
		fi >> array[i][0] >> c >> array[i][1] ;
		if (fi.eof()) {
			cerr << "eof" << endl;
			break;
		}
		cout << array[i][0] << ',' << array[i][1] << ','  << endl;
		i++;
	}
	

	//�t�@�C���̓ǂݍ���
	ifstream ifs("Building.txt");
	if (!ifs){
		cout << "���̓G���[";
		return 1;
	}
	//csv�t�@�C����1�s���ǂݍ���
	double array2[5][10000];
	string str;

	 i = 0;	int j = 0;

		while (getline(ifs, str)){
			
		

			string token;
			istringstream stream(str);

		
				//1�s�̂����A������ƃR���}�𕪊�����
				while (getline(stream, token, ',')){
					//���ׂĕ�����Ƃ��ēǂݍ��܂�邽��
					//���l�͕ϊ����K�v
					double temp = stof(token); //stof(string str) : string��float�ɕϊ�
					array2[i][j] = temp;
					printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%d,%d!!!!!!!!!!!!!!!!!!!!!!\n",i,j);
					printf("%f\n", array2[i][j]);
					
					j = j+1;
					//cout << temp << ", ";

					


				}
				cout << endl;
				i = i + 1;
				j = 0;
			
			
		}
	
	/*
	//csv�t�@�C����1�s���ǂݍ���
	double array2[5][50];
	string str;
	
		for (int i = 0; i < 5; i++){
		while (getline(ifs, str)){

	
			string token;
			istringstream stream(str);

			for (int j = 0; j < 30; j++){
				//1�s�̂����A������ƃR���}�𕪊�����
				while (getline(stream, token, ',')){
					//���ׂĕ�����Ƃ��ēǂݍ��܂�邽��
					//���l�͕ϊ����K�v
					double temp = stof(token); //stof(string str) : string��float�ɕϊ�
					array2[i][j] = temp;
					//cout << temp << ", ";
					
					printf("%f\n", array2[i][j]);


				}
			}
			cout << endl;
		}
	}
	*/
	
	double a = 1000.0;
	int b;
	int gps[500];
	
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 5; j++){
			
			
			 for (int k = 0; k < 30; k++){


				 double Longti = array[i][1] - array2[j][k * 3];
				 double Lati = array[i][0] - array2[j][k * 3 + 1];
				 double dis = sqrt(pow((Lati / 0.0111), 2.0) + pow((Longti / 0.0091), 2.0));
				 ofstream ofs("dis.txt", std::ios::out | std::ios::app);
		         ofs << "dis" <<i<<j<<k <<"=" << dis << endl;
                 ofs.close();
		
				 if (a > dis){
					 a = dis;
					 b = j;
					 printf("%d\n", j);

				 }

			 }
				
			
		}
		a = 1000;
		gps[i] = b;
		//printf("%d", gps[i]);
		ofstream ofs("select.txt", std::ios::out | std::ios::app);
		ofs << "gps" <<i << "=" << gps[i] << endl;
		ofs.close();
		
		
		
		
	}

	
	





	return 0;
}
