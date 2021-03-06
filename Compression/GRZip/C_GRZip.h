#include "../Compression.h"
#include "libGRZip.h"

int __cdecl grzip_compress   (int Method,
                      int BlockSize,
                      int EnableLZP,
                      int MinMatchLen,
                      int HashSizeLog,
                      int AlternativeBWTSort,
                      int AdaptiveBlockSize,
                      int DeltaFilter,
                      CALLBACK_FUNC *callback,
                      void *auxdata);

int __cdecl grzip_decompress (CALLBACK_FUNC *callback,
                      void *auxdata);


#ifdef __cplusplus

// ���������� ������������ ���������� ������� ������ COMPRESSION_METHOD
class GRZIP_METHOD : public COMPRESSION_METHOD
{
public:
  // ��������� ����� ������ ������
  MemSize BlockSize;        // ������ ����� ������, �������������� ���������
  int     Method;
  int     EnableLZP;
  int     MinMatchLen;
  int     HashSizeLog;
  int     AlternativeBWTSort;
  int     AdaptiveBlockSize;
  int     DeltaFilter;

  // �����������, ������������� ���������� ������ ������ �������� �� ���������
  GRZIP_METHOD();

  // ������� ���������� � ��������
  virtual int decompress (CALLBACK_FUNC *callback, void *auxdata);
#ifndef FREEARC_DECOMPRESS_ONLY
  virtual int compress   (CALLBACK_FUNC *callback, void *auxdata);

  // �������� � buf[MAX_METHOD_STRLEN] ������, ����������� ����� ������ � ��� ��������� (�������, �������� � parse_GRZIP)
  virtual void ShowCompressionMethod (char *buf, bool purify);

  // ��������/���������� ����� ������, ������������ ��� ��������/����������, ������ ������� ��� ������ �����
  virtual MemSize GetCompressionMem     (void)         {return BlockSize*9*GetCompressionThreads();}
  virtual MemSize GetDictionary         (void)         {return BlockSize;}
  virtual MemSize GetBlockSize          (void)         {return BlockSize;}
  virtual void    SetCompressionMem     (MemSize mem)  {SetBlockSize (mem/9/GetCompressionThreads());}
  virtual void    SetDecompressionMem   (MemSize mem)  {SetBlockSize (mem/5/GetCompressionThreads());}
  virtual void    SetDictionary         (MemSize dict) {SetBlockSize (dict);}
  virtual void    SetBlockSize          (MemSize bs);
#endif
  virtual MemSize GetDecompressionMem   (void)         {return BlockSize*5*GetCompressionThreads();}
};

// ��������� ������ ������ ������ GRZIP
COMPRESSION_METHOD* parse_GRZIP (char** parameters);

#endif  // __cplusplus
