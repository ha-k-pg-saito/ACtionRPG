#include"../h/Animation.h"

void Animation::InitAnimation(int mhandle, const char* filename[])
{
	for (int i = 0; i < ANIM_LIST::ANIM_NUM; i++)
	{
		m_AnimHandle[i] = MV1LoadModel(filename[i]);
		m_AnimAttachIndex[i] = MV1AttachAnim(mhandle, 0, m_AnimHandle[i], FALSE);
		m_AnimTotalTime[i] = MV1GetAttachAnimTotalTime(mhandle, m_AnimAttachIndex[i]);
	}
}

void Animation::SetAnimation(int mhandle, ANIM_LIST type)
{
	m_PlayTime++;

//��{�I�ȃ��[�v����
//�Đ����Ԃ����Đ����Ԃ𒴂�����0�ɖ߂�
	if (m_PlayTime >= m_AnimTotalTime[type])
	{
		m_PlayTime = 0.f;
	}
	MV1SetAttachAnimTime(mhandle, m_AnimAttachIndex[type], m_PlayTime);
}