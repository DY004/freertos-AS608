#include "as608_test.h"
#include <stdio.h>
#include "as608.h"




void Show_Message(void)
{
    printf("   ������ָ�����ָ����������봰�ڰ��س������ٷ���ָ�����\r\n");
    printf("   ָ��   ------      ���� \r\n");
    printf("    1     ------    ����ָ�� \r\n");
    printf("    2     ------    �Ա�ָ�� \r\n");
    printf("    3     ------    ɾ��ָ���û�ָ��\r\n");
    printf("    4     ------    ���ָ�ƿ�\r\n");
}





/**
  * @brief  ָ��ģ�����
  * @param  ��
  * @retval ��
  */
void  FR_Task(void)
{
    uint32_t   ch;
    scanf("%d",&ch);

    printf("���յ��ַ���%d\r\n",ch);

    switch(ch)
    {
    case 1:
		ch = 0;
        Add_FR();                                    /*����ָ��*/
        Show_Message();
        break;

    case 2:
		ch = 0;
        press_FR();                                /*�ȶ�ָ��*/
        Show_Message();
        break;

    case 3:
		ch = 0;
        Del_FR();                                    /*ɾ��ָ���û�ָ��*/
        Show_Message();
        break;

    case 4:
		ch = 0;
        Del_FR_Lib();                                  /*���ָ�ƿ�*/
        Show_Message();
        break;

    default:
        /* �������ָ��ָ���ַ�����ӡ��ʾ��Ϣ */
        printf("������Ϸ�ָ�\r\n\r\n");
        Show_Message();
        break;
    }
	
    return;
}


