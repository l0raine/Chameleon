#pragma once

#define m_nIndex					0x64

#define m_nModelIndex				0x254
#define m_hWeapon					0x29B8
#define m_hOwner					0x29BC

#define m_lifeState					0x25B
#define m_hMyWeapons				0x2DE8
#define m_hViewModel				0x32F0

#define m_AttributeManager			0x2D70
#define m_Item						0x40
#define m_iItemDefinitionIndex		0x1D8
#define m_iItemIDHigh				0x1F0
#define m_iAccountID				0x1F8
#define m_iEntityQuality			0x1DC
#define m_szCustomName				0x26C
#define m_OriginalOwnerXuidLow		0x3160
#define m_OriginalOwnerXuidHigh		0x3164
#define m_nFallbackPaintKit			0x3168
#define m_nFallbackSeed				0x316C
#define m_flFallbackWear			0x3170
#define m_nFallbackStatTrak			0x3174

class IClientEntity {
	public:
		inline int GetIndex() {
			return *(int*)((DWORD)this + m_nIndex);
		}
};

class CBaseViewModel: public IClientEntity {
	public:
		inline int GetModelIndex() {
			// DT_BaseViewModel -> m_nModelIndex
			return *(int*)((DWORD)this + m_nModelIndex);
		}

		inline DWORD GetOwner() {
			// DT_BaseViewModel -> m_hOwner
			return *(PDWORD)((DWORD)this + m_hOwner);
		}

		inline DWORD GetWeapon() {
			// DT_BaseViewModel -> m_hWeapon
			return *(PDWORD)((DWORD)this + m_hWeapon);
		}

		inline void SetWeaponModel(const char* Filename, IClientEntity* Weapon) {
			return CallVirtualFunction<void(__thiscall*)(void*, const char*, IClientEntity*)>(this, 242)(this, Filename, Weapon);
		}
};

class CBasePlayer: public IClientEntity {
	public:
		inline BYTE GetLifeState() {
			// DT_BasePlayer -> m_lifeState
			return *(BYTE*)((DWORD)this + m_lifeState);
		}

		inline UINT* GetWeapons() {
			// DT_BasePlayer -> m_hMyWeapons
			return (UINT*)((DWORD)this + m_hMyWeapons);
		}

		inline CBaseViewModel* GetViewModel() {
			// DT_BasePlayer -> m_hViewModel
			return (CBaseViewModel*)g_EntityList->GetClientEntityFromHandle(*(PDWORD)(this + m_hViewModel));
		}
};

class CBaseAttributableItem: public IClientEntity {
	public:
		inline int* GetItemDefinitionIndex() {
			// DT_BaseAttributableItem -> m_AttributeManager -> m_Item -> m_iItemDefinitionIndex
			return (int*)((DWORD)this + m_AttributeManager + m_Item + m_iItemDefinitionIndex);
		}

		inline int* GetItemIDHigh() {
			// DT_BaseAttributableItem -> m_AttributeManager -> m_Item -> m_iItemIDHigh
			return (int*)((DWORD)this + m_AttributeManager + m_Item + m_iItemIDHigh);
		}

		inline int* GetAccountID() {
			// DT_BaseAttributableItem -> m_AttributeManager -> m_Item -> m_iAccountID
			return (int*)((DWORD)this + m_AttributeManager + m_Item + m_iAccountID);
		}
	
		inline int* GetEntityQuality() {
			// DT_BaseAttributableItem -> m_AttributeManager -> m_Item -> m_iEntityQuality
			return (int*)((DWORD)this + m_AttributeManager + m_Item + m_iEntityQuality);
		}

		inline char* GetCustomName() {
			// DT_BaseAttributableItem -> m_AttributeManager -> m_Item -> m_szCustomName
			return (char*)((DWORD)this + m_AttributeManager + m_Item + m_szCustomName);
		}

		inline int* GetOriginalOwnerXuidLow() {
			// DT_BaseAttributableItem -> m_OriginalOwnerXuidLow
			return (int*)((DWORD)this + m_OriginalOwnerXuidLow);
		}

		inline int* GetOriginalOwnerXuidHigh() {
			// DT_BaseAttributableItem -> m_OriginalOwnerXuidHigh
			return (int*)((DWORD)this + m_OriginalOwnerXuidHigh);
		}

		inline int* GetFallbackPaintKit() {
			// DT_BaseAttributableItem -> m_nFallbackPaintKit
			return (int*)((DWORD)this + m_nFallbackPaintKit);
		}

		inline int* GetFallbackSeed() {
			// DT_BaseAttributableItem -> m_nFallbackSeed
			return (int*)((DWORD)this + m_nFallbackSeed);
		}

		inline float* GetFallbackWear() {
			// DT_BaseAttributableItem -> m_flFallbackWear
			return (float*)((DWORD)this + m_flFallbackWear);
		}

		inline int* GetFallbackStatTrak() {
			// DT_BaseAttributableItem -> m_nFallbackStatTrak
			return (int*)((DWORD)this + m_nFallbackStatTrak);
		}
};