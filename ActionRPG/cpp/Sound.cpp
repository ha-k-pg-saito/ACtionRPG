#include"../h/Sound.h"

void Sound::Load()
{
	//�T�E���h�t�@�C����ǂݍ���
	m_SoundHandle[0] = LoadSoundMem("�����t�@�C��");
	m_SoundHandle[1] = LoadSoundMem("�����t�@�C��");
	m_SoundHandle[2] = LoadSoundMem("�����t�@�C��");
}

void Sound::Init()
{
	Load();
}

void Sound::play()
{
	//�T�E���h�Đ�(���[�v)
	PlaySoundMem(m_SoundHandle[0],DX_PLAYTYPE_LOOP);
	PlaySoundMem(m_SoundHandle[1],DX_PLAYTYPE_LOOP);
	PlaySoundMem(m_SoundHandle[2],DX_PLAYTYPE_LOOP);
}

void Sound::stop()
{
	//�T�E���h���~�߂�
	StopSoundMem(m_SoundHandle[0]);
	StopSoundMem(m_SoundHandle[1]);
	StopSoundMem(m_SoundHandle[2]);
}