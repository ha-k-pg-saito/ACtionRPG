#include"../h/Sound.h"

void Sound::Init(int sound)
{
	//�T�E���h�t�@�C����ǂݍ���
	m_SoundHandle = sound;
}

void Sound::play()
{
	//�T�E���h�Đ�(���[�v)
	PlaySoundMem(m_SoundHandle, DX_PLAYTYPE_LOOP);
}

void Sound::stop()
{
	//�T�E���h���~�߂�
	StopSoundMem(m_SoundHandle);
}