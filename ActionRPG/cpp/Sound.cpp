#include"../h/Sound.h"

void Sound::Load()
{
	//�T�E���h�t�@�C����ǂݍ���
	SoundHandle = LoadSoundMem("�����t�@�C��");
}

void Sound::play()
{
	//�T�E���h�Đ�
	PlaySoundFile("�����t�@�C��",DX_PLAYTYPE_LOOP);
}

void Sound::stop()
{
	//�T�E���h���~�߂�
	StopSoundFile();
}