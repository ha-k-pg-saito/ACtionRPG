#include"../h/Sound.h"

void Sound::Init(int soundhandle)
{
	//�T�E���h�t�@�C����ǂݍ���
	m_SoundHandle = soundhandle;
}

void Sound::play()
{
	//�T�E���h�Đ�(���[�v)
	PlaySoundMem(m_SoundHandle, DX_PLAYTYPE_BACK,FALSE);
}

void Sound::stop()
{
	//�T�E���h���~�߂�
	StopSoundMem(m_SoundHandle);
}