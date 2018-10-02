#pragma once
#include <UI/ViewPane/ViewPane.h>
#include <UI/Controls/StyleTreeCtrl.h>

namespace viewpane
{
	class TreePane : public ViewPane
	{
	public:
		static TreePane* Create(int paneID, UINT uidLabel, bool bReadOnly);

		ULONG HandleChange(UINT nID) override;
		bool IsDirty() override;

	private:
		void Initialize(_In_ CWnd* pParent, _In_ HDC hdc) override;
		void DeferWindowPos(_In_ HDWP hWinPosInfo, _In_ int x, _In_ int y, _In_ int width, _In_ int height) override;
		void CommitUIValues() override;
		int GetMinWidth(_In_ HDC hdc) override;
		int GetFixedHeight() override;
		int GetLines() override;

		bool m_bDirty{false};
		bool m_bAllowSort{false};

		controls::StyleTreeCtrl m_Tree;
	};
} // namespace viewpane