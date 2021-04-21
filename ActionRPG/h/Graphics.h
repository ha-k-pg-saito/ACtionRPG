#ifndef Graphics_h_
#define Graphics_h_

class Graphics
{
public:
	//�V���O���g��
	static Graphics* Instance()
	{
		static Graphics instance;

		return &instance;
	}

private:
	void InitTexture();			
	void ReleaseTexture();		
	void Start();				//�`��J�n
	void End();					//�`��I��

private:
	//�C���X�^���X����h�����߂̏���
	Graphics() {}
};

#endif