#include"../h/Sound.h"

void Sound::Load()
{
	//�T�E���h�t�@�C����ǂݍ���
	SoundHandle[0] = LoadSoundMem("�����t�@�C��");
	SoundHandle[1] = LoadSoundMem("�����t�@�C��");
	SoundHandle[2] = LoadSoundMem("�����t�@�C��");
}

void Sound::play()
{
	//�T�E���h�Đ�(���[�v)
	PlaySoundMem(SoundHandle[0],DX_PLAYTYPE_LOOP);
	PlaySoundMem(SoundHandle[1],DX_PLAYTYPE_LOOP);
	PlaySoundMem(SoundHandle[2],DX_PLAYTYPE_LOOP);
}

void Sound::stop()
{
	//�T�E���h���~�߂�
	StopSoundMem(SoundHandle[0]);
	StopSoundMem(SoundHandle[1]);
	StopSoundMem(SoundHandle[2]);
}