#ifndef Texture_h_
#define Texture_h_

#include <map>
#include <string>
#include<iostream>

class Texture
{
public:
	//�V���O���g��
	static Texture* Instance()
	{
		static Texture instance;

		return &instance;
	}
	
public:
	void LoadTexture();									//�摜�̓ǂݍ���
	bool DrawTexture(std::map<std::string,int>);		//�摜�̕`��

private:
	Texture() {}


};

#endif