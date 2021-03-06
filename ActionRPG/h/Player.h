#ifndef Player_h_
#define Player_h_
#include"DxLib.h"
#include"../h/Base.h"
#include"../h/Map.h"
#include"../h/Enemy.h"
#include"../h/Animation.h"

class Player :public CharBase
{
//動いたかどうかで状態を変化させる
	enum PlayerState
	{
		None,
		OnMove
	};
public:
	//プレイヤ内でマップ情報を更新している
	Player(Map* map) :
		//CharBase({pos},hp,speed)を初期化している
		CharBase({ 0.f, -3.f, 0.f }, 4, 40.f),
		m_ModelHandle{ 0 },
		m_Radian{ 0.f },
		m_PlayTime{ 0.f },
		m_Direction{ 0.f,0.f,1.f },
		m_Digree_Y{ 0.f },
		m_HitCounter{ 0 },
		m_OldMoveVec{ 0.f },
		m_HeightCapsule{ 0.f,9.f,0.f },
		m_RotateSpeed{ 5.f },
		m_InitRad{0.f},
		IsAlive{ true }
	{
		m_MapRef = map;
	}

	~Player() { Release(); }

public:
// プレイヤーのモデル取得
	int    GetModel() { return m_ModelHandle; }
//プレイヤのHpカウンタ―取得
	int GetAliveFlag() { return IsAlive; }
//pos変数に反映させる
	void SetPos(VECTOR setpos) { m_Pos = setpos; }
//プレイヤーの座標取取得
	VECTOR GetPos() { return m_Pos; }
// プレイヤーの移動ベクトル取得
	VECTOR GetMoveVec() { return m_OldMoveVec; }
//プレイヤの高さを取得
	VECTOR GetHeight() { return m_HeightCapsule; }

public:
	void Init();			   //初期化
	void Update();			   //更新（統括）
	void UpdateAnimation();	   //アニメーション更新
	void Draw();			   //描画関数
	void DrawHP(); 			   //HP描画
	void Release();			   //削除する
	void Attack();			   //攻撃する
	void Damage();			   //ダメージカウンタ―増やす->HP変動

private:
	void Rotate();			   //回転する
	void Move();			   //行動する

private:
//Playerのアニメーション数
#define PLAYER_ANIM_NUM 6
//60フレームで割るときに使う
#define FPS 60.f

#define RAY_ORIGIN 4.f
#define RAY_DOWN   -16.f
// 3Dモデルを保存する変数
	int m_ModelHandle;
//3Dモデルに貼るテクスチャ保存変数
	int m_GrHandle;
	int m_SwordGrHandle;
//Ekardにつける剣のモデル保存変数
	int m_SwordHandle;
//アニメーション時間
	float m_PlayTime;						
//計算で使う変数
	float  m_Radian;		
	float  m_Digree_Y;	
	VECTOR m_Direction;	
//当たった回数を保存する変数
	int m_HitCounter;
//生存フラグ
	bool IsAlive;
//キャラの移動量保存変数
	VECTOR m_OldMoveVec;       
//レイの始点に使う変数
	VECTOR m_StartLine;
	VECTOR m_EndLine;
//カプセルの当たり判定で使用する変数
	VECTOR m_HeightCapsule;

	VECTOR m_InitRad;
//回転スピード
	float m_RotateSpeed;

//スケール保存変数
	VECTOR Scale;
	 
	VECTOR m_SwordPos;

//マップモデル初期化
	Map* m_MapRef;
//インスタンス化
	Enemy Enemy;
	Animation Anim;
	
//アニメーションリスト変数化
	ANIM_LIST m_AnimKind;
};
#endif // !Player_h_