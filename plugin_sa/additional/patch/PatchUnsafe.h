class PatchUnsafe {
public:
  template < class T > void PatchUnsafe (DWORD address, T data)
  {
	  (*(T*)address) = data;
  }
};
