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

void Animation::SetAnimation(int mhandle, ANIM_LIST type, float playtime)
{
	MV1SetAttachAnimTime(mhandle, m_AnimAttachIndex[type], playtime);
}