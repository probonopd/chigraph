#pragma once

#ifndef CHIGGUI_PARAMLISTWIDGET_HPP
#define CHIGGUI_PARAMLISTWIDGET_HPP

#include <QListWidget>
#include <QTableView>

#include <chig/GraphModule.hpp>

class FunctionView;

inline QStringList createTypeOptions(const chig::GraphModule& mod) {
	QStringList ret;

	// add the module
	for (const auto& ty : mod.typeNames()) {
		ret << QString::fromStdString(mod.fullName() + ":" + ty);
	}

	// and its dependencies
	for (auto dep : mod.dependencies()) {
		auto depMod = mod.context().moduleByFullName(dep);
		for (const auto& type : depMod->typeNames()) {
			ret << QString::fromStdString(depMod->fullName() + ":" + type);
		}
	}
	return ret;
}
class ParamListWidget : public QWidget {
	Q_OBJECT

public:
	enum Type { Input, Output };

	ParamListWidget(QWidget* parent = nullptr);

	void setFunction(FunctionView* func, Type ty);
signals:
	void dirtied();

private:
	void refreshEntry();
	void refreshExits();

	QListWidget*  mParamList;
	FunctionView* mFunc = nullptr;
	Type          mType;
};

#endif  // CHIGGUI_PARAMLISTWIDGET_HPP
