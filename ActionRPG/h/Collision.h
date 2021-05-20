#ifndef Collison_h_
#define Collison_h_

#include "DxLib.h"
#include "../h/Player.h"
#include "../h/Map.h"

class Collision
{
public:
	Collision();
	~Collision();

	void Update(Player *player, Map *map);
	void Draw();

private:
	MV1_COLL_RESULT_POLY_DIM HitDim;			// �L�����N�^�[�̎��͂ɂ���|���S�������o�������ʂ��������铖���蔻�茋�ʍ\����
	int Add, y, i;
	VECTOR SpherePos;
	int KabeNum;						// �ǃ|���S���Ɣ��f���ꂽ�|���S���̐�
	int YukaNum;                        // ���|���S���Ɣ��f���ꂽ�|���S���̐�

#define CHARA_MAX_HITCOLL			2048		// ��������R���W�����|���S���̍ő吔
	MV1_COLL_RESULT_POLY *Kabe[CHARA_MAX_HITCOLL];	// �ǃ|���S���Ɣ��f���ꂽ�|���S���̍\���̂̃A�h���X��ۑ����Ă������߂̃|�C���^�z��
	MV1_COLL_RESULT_POLY *Yuka[CHARA_MAX_HITCOLL];	// ���|���S���Ɣ��f���ꂽ�|���S���̍\���̂̃A�h���X��ۑ����Ă������߂̃|�C���^�z��

};

#endif // !1



