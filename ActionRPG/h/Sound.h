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
	void Init(int sound);
	void play();
	void stop();

public:
	//�T�E���h�̃n���h����ۑ�����ϐ�
	int m_SoundHandle[3];

private:
	Sound() {}
};


#endif