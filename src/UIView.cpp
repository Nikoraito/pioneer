// Copyright © 2008-2012 Pioneer Developers. See AUTHORS.txt for details
// Licensed under the terms of the GPL v3. See licenses/GPL-3.txt

#include "UIView.h"
#include "Pi.h"
#include "ui/Context.h"
#include "gameui/Panel.h"

void UIView::Update()
{
	Pi::ui->Update();
}

void UIView::Draw3D()
{
	Pi::ui->Draw();
}

void UIView::OnSwitchTo()
{
	Pi::ui->SetInnerWidget(
		Pi::ui->VBox()
			->PackEnd(Pi::ui->CallTemplate(m_templateName))
			->PackEnd(new GameUI::Panel(Pi::ui.Get()))
	);
}

void UIView::OnSwitchFrom()
{
	Pi::ui->RemoveInnerWidget();
	Pi::ui->Layout(); // UI does important things on layout, like updating keyboard shortcuts
}
