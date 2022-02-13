/*
 * Xournal++
 *
 * Scroll handler
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <string>
#include <vector>

#include <gtk/gtk.h>

#include "gui/widgets/SpinPageAdapter.h"
#include "model/PageRef.h"


class XojPage;
class Control;

class ScrollHandler: public SpinPageListener {
public:
    ScrollHandler(Control* control);
    ~ScrollHandler() override;

public:
    void goToPreviousPage();
    void goToNextPage();

    void goToLastPage();
    void goToFirstPage();

    void scrollToPage(const PageRef& page, double top = 0);
    void scrollToPage(size_t page, double top = 0);

    void scrollToAnnotatedPage(bool next);

    bool isPageVisible(size_t page, int* visibleHeight = nullptr);

public:
    void pageChanged(size_t page) override;

private:
    void scrollToSpinPage();

private:
    Control* control = nullptr;
};