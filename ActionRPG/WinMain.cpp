#include "DxLib.h"
#include "h/Player.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	Player player;  // PlayerClass�̃��[�J���ϐ�
	//int m_Player = 0;
	 
	//�E�C���h�E���[�h�ɕύX
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);					//�E�B���h�E���[�h
	SetGraphMode(640, 480, 32);				//��ʃ��[�h�ύX
	SetBackgroundColor(0, 0, 0);			//�w�i�F
	SetFontSize(75);						//�t�H���g�T�C�Y
	if (DxLib_Init() == -1)					//�c�w���C�u��������������
	{
		return -1;							//�G���[���N�����璼���ɏI��
	}
	// ���f���n���h���̍폜
	//MV1DeleteModel(m_Player);

	player.Update();
	// ���f���̓ǂݍ���
	//m_Player = MV1LoadModel("Tex/unitychan.mv1");

	// ��ʂɈڂ郂�f���̈ړ�
	//MV1SetPosition(m_Player, VGet(320.0f, -300.0f, 600.0f));

	//�Q�[�����[�v
	while (true)
	{
		if (ProcessMessage() != 0)
		{
			break;
		}

		ClearDrawScreen();					//�`�悳�ꂽ���̍폜
		clsDx();							//�����폜
		// 3D���f���̕`��
		//MV1DrawModel(m_Player);

		player.Draw();
		
		ScreenFlip();						//��ʍX�V


		//clsDx();

	}

	DxLib_End();							 // �c�w���C�u�����g�p�̏I������
	SetDrawScreen(DX_SCREEN_BACK);

	return 0;								 // �\�t�g�̏I�� 
}