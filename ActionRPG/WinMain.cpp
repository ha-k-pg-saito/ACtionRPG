<<<<<<< HEAD
#include"DxLib.h"
#include"h/Camera.h"
=======
#include "DxLib.h"
#include "h/Player.h"
>>>>>>> cd424402c48c74a7e30de5e110a747f3ccfdff7d

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	
	Player player;

	//�E�C���h�E���[�h�ɕύX
	SetOutApplicationLogValidFlag(FALSE);
<<<<<<< HEAD
	ChangeWindowMode(TRUE);					//�E�B���h�E���[�h
	SetGraphMode(640, 480, 32);				//��ʃ��[�h�ύX
	SetBackgroundColor(0, 0, 0);			//�w�i�F
	SetFontSize(75);						//�t�H���g�T�C�Y
=======
	ChangeWindowMode(TRUE);				//�E�B���h�E���[�h
	SetGraphMode(640, 480, 32);		//��ʃ��[�h�ύX
	SetBackgroundColor(0, 0, 0);	//�w�i�F
	SetFontSize(75);					//�t�H���g�T�C�Y
	SetCameraNearFar(1.f,150.f);
>>>>>>> cd424402c48c74a7e30de5e110a747f3ccfdff7d

	if (DxLib_Init() == -1)					//�c�w���C�u��������������
	{
		return -1;							//�G���[���N�����璼���ɏI��
	}

<<<<<<< HEAD
	SetDrawScreen(DX_SCREEN_BACK);			//���ʂɕ`��
=======
	player.Update();
>>>>>>> cd424402c48c74a7e30de5e110a747f3ccfdff7d

	//�Q�[�����[�v
	while (true)
	{
		if (ProcessMessage() != 0)
		{
			break;
		}

<<<<<<< HEAD
		ClearDrawScreen();					//�`�悳�ꂽ���̍폜
		clsDx();							//�����`��
=======
		//��ʃN���A
		ClearDrawScreen();

		player.Draw();

		//clsDx();
>>>>>>> cd424402c48c74a7e30de5e110a747f3ccfdff7d

		
		ScreenFlip();						//��ʍX�V

	}

<<<<<<< HEAD
	DxLib_End();							 // �c�w���C�u�����g�p�̏I������
=======
	SetDrawScreen(DX_SCREEN_BACK);

	DxLib_End();    // �c�w���C�u�����g�p�̏I������
>>>>>>> cd424402c48c74a7e30de5e110a747f3ccfdff7d

	return 0;								 // �\�t�g�̏I�� 
}