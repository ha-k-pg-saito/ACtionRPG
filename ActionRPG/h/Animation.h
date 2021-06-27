#ifndef Animation_h_ 
#define Animation_h_

#include"DxLib.h"

enum ANIM_LIST
	{
		ANIM_IDLE,	   //�ҋ@
		ANIM_RUN,	   //����
		ANIM_ATTACK,   //�U��
		ANIM_DAMAGE,   //�_���[�W
		ANIM_DIED,	   //���S
		ANIM_NUM,	   
	};

class Animation
{
public:
//�A�j���[�V�����penum
	

	Animation() :
		m_AnimHandle{ 0 },
		m_AnimAttachIndex{ 0 },
		m_AnimTotalTime{ 0 },
		m_PlayTime{ 0.f }
	{}
	~Animation() {}

	//�A�j���[�V�����p�ϐ�
	int m_AnimHandle[ANIM_NUM];
	int m_AnimAttachIndex[ANIM_NUM];
	int m_AnimTotalTime[ANIM_NUM];
	float m_PlayTime;

	//�A�j���[�V�����̓ǂݍ��݁E�A�^�b�`�E���Đ����Ԏ擾
	//�����[�����f���n���h���A������
	void InitAnimation(int mhandle, const char* filename[]);

	//�A�j���[�V������؂�ւ��邽�߂̊֐�
	//�����[�����f���n���h���A�A�j���[�V�����ԍ��A���Đ�����
	void SetAnimation(int mhandle, ANIM_LIST type);
};
#endif 