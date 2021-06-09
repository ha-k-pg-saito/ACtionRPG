//#ifndef Collison_h_
//#define Collison_h_
//
//#include "DxLib.h"
//#include <math.h>
//#include "../h/Player.h"
//#include "../h/Map.h"
//
//#define PLAYER_ENUM_DEFAULT_SIZE		800.0f		// ���͂̃|���S�����o�Ɏg�p���鋅�̏����T�C�Y
//
//class Collision
//{
//public:
//	Collision();
//	~Collision();
//
//	void Update(Player *player);
//	void Draw();
//
//private:
//	MV1_COLL_RESULT_POLY_DIM HitDim;			// �L�����N�^�[�̎��͂ɂ���|���S�������o�������ʂ��������铖���蔻�茋�ʍ\����
//	int Add, y, i;
//	VECTOR SpherePos;
//	int KabeNum;						// �ǃ|���S���Ɣ��f���ꂽ�|���S���̐�
//	int YukaNum;                        // ���|���S���Ɣ��f���ꂽ�|���S���̐�
//	int HitFlag;                        // �|���S���ɓ����������ǂ������L�����Ă����̂Ɏg���ϐ�( �O:�������Ă��Ȃ�  �P:�������� )  
//	int MoveFlag;						// ���������Ɉړ��������ǂ����̃t���O( �O:�ړ����Ă��Ȃ�  �P:�ړ����� )
//	HITRESULT_LINE LineRes;				// �����ƃ|���S���Ƃ̓����蔻��̌��ʂ�������\����
//	VECTOR NowPos;
//
//#define CHARA_MAX_HITCOLL			2048		// ��������R���W�����|���S���̍ő吔
//	MV1_COLL_RESULT_POLY *Kabe[CHARA_MAX_HITCOLL];	// �ǃ|���S���Ɣ��f���ꂽ�|���S���̍\���̂̃A�h���X��ۑ����Ă������߂̃|�C���^�z��
//	MV1_COLL_RESULT_POLY *Yuka[CHARA_MAX_HITCOLL];	// ���|���S���Ɣ��f���ꂽ�|���S���̍\���̂̃A�h���X��ۑ����Ă������߂̃|�C���^�z��
//	MV1_COLL_RESULT_POLY* Poly;
//};
//#endif // !