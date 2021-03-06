#include "../Compression.h"

int ppmd_compress2   (int ENCODE, int order, MemSize mem, int MRMethod, MemSize chunk, CALLBACK_FUNC *callback, void *auxdata);
int ppmd_decompress2 (int ENCODE, int order, MemSize mem, int MRMethod, MemSize chunk, CALLBACK_FUNC *callback, void *auxdata);


#ifdef __cplusplus

// ���������� ������������ ���������� ������� ������ COMPRESSION_METHOD
class PPMD_METHOD : public COMPRESSION_METHOD
{
public:
  // ��������� ����� ������ ������
  int     order;     // ������� ������ (�� �������� ��������� �������� ��������������� ���������)
  MemSize mem;       // ����� ������, ������������ ��� �������� ������
  int     MRMethod;  // ��� ������, ����� ������, ���������� ��� �������� ������, ���������
  MemSize chunk;     // ������ ���������� ����� ��� compress_all_at_once

  // �����������, ������������� ���������� ������ ������ �������� �� ���������
  PPMD_METHOD();

  // ������� ���������� � ��������
  virtual int decompress (CALLBACK_FUNC *callback, void *auxdata);
#ifndef FREEARC_DECOMPRESS_ONLY
  virtual int compress (CALLBACK_FUNC *callback, void *auxdata);

  // �������� � buf[MAX_METHOD_STRLEN] ������, ����������� ����� ������ � ��� ��������� (�������, �������� � parse_PPMD)
  virtual void ShowCompressionMethod (char *buf, bool purify);

  // ��������/���������� ����� ������, ������������ ��� ��������/����������, ������ ������� ��� ������ �����
  virtual MemSize GetCompressionMem     (void)          {return mem;}
  virtual MemSize GetDictionary         (void)          {return 0;}
  virtual MemSize GetBlockSize          (void)          {return 0;}
  virtual void    SetCompressionMem     (MemSize _mem);
  virtual void    SetDecompressionMem   (MemSize _mem)  {SetCompressionMem(_mem);}
  virtual void    SetDictionary         (MemSize dict)  {}
  virtual void    SetBlockSize          (MemSize bs)    {}
#endif
  virtual MemSize GetDecompressionMem   (void)          {return mem;}
};

// ��������� ������ ������ ������ PPMD
COMPRESSION_METHOD* parse_PPMD (char** parameters);

#endif  // __cplusplus
