#ifndef Animation_h_ 
#define Animation_h_

#include"DxLib.h"

class Animation
{
public:
	//�A�j���[�V�����penum
	enum ANIM_LIST
	{
		ANIM_WAIT,
		ANIM_RUN,
		ANIM_ATTACK,
		ANIM_DAMAGE,
		ANIM_DIED,
		ANIM_NUM,
	};

	//�A�j���[�V�����p�ϐ�
	int m_AnimHandle[ANIM_NUM];
	int m_AnimAttachIndex[ANIM_NUM];
	int m_AnimTotalTime[ANIM_NUM];

	//�A�j���[�V�����̓ǂݍ��݁E�A�^�b�`�E���Đ����Ԏ擾
	//�����[�����f���n���h���A������
	void InitAnimation(int mhandle, const char* filename[]);

	//�A�j���[�V������؂�ւ��邽�߂̊֐�
	//�����[�����f���n���h���A�A�j���[�V�����ԍ��A���Đ�����
	void SetAnimation(int mhandle, ANIM_LIST type, float playtime);
};
#endif 