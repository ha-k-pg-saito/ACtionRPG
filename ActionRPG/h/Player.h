#ifndef Player_h_
#define Player_h_
#include"DxLib.h"
#include"../h/Base.h"
#include"../h/Map.h"
#include"../h/Enemy.h"
#include"../h/Animation.h"

class Player :public CharBase
{
//���������ǂ����ŏ�Ԃ�ω�������
	enum PlayerState
	{
		None,
		OnMove
	};
public:
	//�v���C�����Ń}�b�v�����X�V���Ă���
	Player(Map* map) :
		//CharBase({pos},hp,speed)�����������Ă���
		CharBase({ 0.f, 0.f, 0.f }, 0, 40.f),
		m_ModelHandle{ 0 },
		m_Radian{ 0.f },
		m_PlayTime{ 0.f },
		m_Direction{ 0.f,0.f,1.f },
		m_Digree_Y{ 0.f },
		m_StartLine{ 0.f },
		m_EndLine{ 0.f },
		m_HitCounter{ 0 },
		m_OldMoveVec{ 0.f },
		m_HeightCapsule{ 0.f,6.f,0.f },
		m_RotateSpeed{ 5.f },		
		IsAlive{ true }
	{
		m_MapRef = map;
	}

	~Player() { Release(); }

public:
// �v���C���[�̃��f���擾
	int    GetModel() { return m_ModelHandle; }
//�v���C����Hp�J�E���^�\�擾
	int GetAliveFlag() { return IsAlive; }
//pos�ϐ��ɔ��f������
	void SetPos(VECTOR setpos) { m_Pos = setpos; }
//�v���C���[�̍��W��擾
	VECTOR GetPos() { return m_Pos; }
// �v���C���[�̈ړ��x�N�g���擾
	VECTOR GetMoveVec() { return m_OldMoveVec; }
//�v���C���̍������擾
	VECTOR GetHeight() { return m_HeightCapsule; }


public:
	void Init();
	void Update();
	void Draw();
	void DrawHP(); 
	void Release();
	void Attack();
	void Damage();

private:
	void Rotate();
	void Move();

private:
//Player�̃e�N�X�`����
#define PLAYER_TEX_NUM  8
//Player�̃A�j���[�V������
#define PLAYER_ANIM_NUM 6

// 3D���f����ۑ�����ϐ�
	int m_ModelHandle;
//3D���f���ɓ\��e�N�X�`���ۑ��ϐ�
	int m_GrHandle[PLAYER_TEX_NUM];

//�A�j���[�V��������
	float m_PlayTime;						

//�v�Z�Ŏg���ϐ�
	float  m_Radian;		
	float  m_Digree_Y;	
	VECTOR m_Direction;	

//���������񐔂�ۑ�����ϐ�
	int m_HitCounter;
//�����t���O
	bool IsAlive;
//�L�����̈ړ��ʕۑ��ϐ�
	VECTOR m_OldMoveVec;       
//���C�̎n�_�Ɏg���ϐ�
	VECTOR m_StartLine;
	VECTOR m_EndLine;
//�J�v�Z���̓����蔻��Ŏg�p����ϐ�
	VECTOR m_HeightCapsule;

//��]�X�s�[�h
	float m_RotateSpeed;

//�}�b�v���f��������
	Map* m_MapRef;
	Enemy Enemy;
	Animation Anim;
	
};
#endif // !Player_h_