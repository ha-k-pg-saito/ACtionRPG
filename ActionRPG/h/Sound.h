#ifndef Sound_h_
#define Sound_h_

#include"DxLib.h"

class Sound
{
public:
	//�V���O���g��
	static Sound* Instance()
	{
		static Sound instance;
		return &instance;
	}

public:
	void Load();
	void play();
	void stop();

public:
	//�T�E���h�̃n���h����ۑ�����ϐ�
	int SoundHandle[3];

private:
	Sound() {}
	~Sound() {}
};


#endif