#include"../h/Sound.h"

void Sound::Init(int sound)
{
	//�T�E���h�t�@�C����ǂݍ���
	m_SoundHandle[3] = sound;
}

void Sound::play()
{
	//�T�E���h�Đ�(���[�v)
	PlaySoundMem(m_SoundHandle[0], DX_PLAYTYPE_LOOP);
}

void Sound::stop()
{
	//�T�E���h���~�߂�
	StopSoundMem(m_SoundHandle[0]);
}