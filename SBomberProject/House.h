#pragma once
#include <iostream>
#include <stdint.h>

#include "DestroyableGroundObject.h"
#include <vector>



class House : public DestroyableGroundObject
{

public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;



	void SetMatixForDraw(const std::vector<std::string>& m_Strs_) {

		this->m_Strs_ = m_Strs_;
	}

private:

	const uint16_t score = 1500; //$$$

	std::vector<std::string> m_Strs_;

};


/**
 * Интерфейс Строителя объявляет создающие методы для различных частей объектов
 * Продуктов.
 */
class HouseBuilder{
public:
	virtual ~HouseBuilder() {}
	virtual void ProducePartA() const = 0;
	virtual void ProducePartB() const = 0;
	virtual void ProducePartC() const = 0;
};
/**
 * Классы Конкретного Строителя следуют интерфейсу Строителя и предоставляют
 * конкретные реализации шагов построения. Ваша программа может иметь несколько
 * вариантов Строителей, реализованных по-разному.
 */
class HouseBuilderA : public HouseBuilder{
private:
	House* product;
	/**
	 * Новый экземпляр строителя должен содержать пустой объект продукта,
	 * который используется в дальнейшей сборке.
	 */
public:
	HouseBuilderA() {
		this->Reset();
	}
	~HouseBuilderA(){
		delete product;
	}
	void Reset() {
		this->product = new House();
	}

	/**
	 * Все этапы производства работают с одним и тем же экземпляром продукта.
	 */

	void ProducePartA()const override {

		std::vector<std::string> Strs;

		//Strs.push_back("01234567890123");
		Strs.push_back("              ");
		Strs.push_back(" ▄█▀█▄  ▄███▄ ");
		Strs.push_back("▐█░██████████▌");
		Strs.push_back(" ██▒█████████ ");
		Strs.push_back("  ▀████████▀  ");
		Strs.push_back("     ▀██▀     ");

		this->product->SetMatixForDraw(Strs);
	}

	void ProducePartB()const override {

		std::vector<std::string> Strs;

		//Strs.push_back("01234567890123");
		Strs.push_back("              ");
		Strs.push_back("  ▄█▀█▄▄███▄  ");
		Strs.push_back(" ▐█░████████▌ ");
		Strs.push_back("  ██▒███████  ");
		Strs.push_back("   ▀██████▀   ");
		Strs.push_back("      ▀▀      ");

		this->product->SetMatixForDraw(Strs);
	}

	void ProducePartC()const override {

		std::vector<std::string> Strs;
		Strs.push_back("                 ");
		Strs.push_back("   █ █ █ █ █ █   ");
		Strs.push_back("   ███████████   ");
		Strs.push_back("   ██ ████ ███   ");
		Strs.push_back("  ▀███████████▀  ");
		Strs.push_back("     ███████     ");
		Strs.push_back("    █████████    ");
		Strs.push_back("    █ ████ ██    ");
		Strs.push_back("    █████████    ");
		Strs.push_back("    █ ████ ██    ");
		Strs.push_back("  ▀███████████▀  ");
		Strs.push_back("   ▀▀       ▀▀   ");
		this->product->SetMatixForDraw(Strs);
	}

	//void ProducePartC()const override {
	//	this->product->parts_.push_back("PartC1");
	//}
    /**
	 * Конкретные Строители должны предоставить свои собственные методы
	 * получения результатов. Это связано с тем, что различные типы строителей
	 * могут создавать совершенно разные продукты с разными интерфейсами.
	 * Поэтому такие методы не могут быть объявлены в базовом интерфейсе
	 * Строителя (по крайней мере, в статически типизированном языке
	 * программирования). Обратите внимание, что PHP является динамически
	 * типизированным языком, и этот метод может быть в базовом интерфейсе.
	 * Однако мы не будем объявлять его здесь для ясности.
	 *
	 * Как правило, после возвращения конечного результата клиенту, экземпляр
	 * строителя должен быть готов к началу производства следующего продукта.
	 * Поэтому обычной практикой является вызов метода сброса в конце тела
	 * метода getProduct. Однако такое поведение не является обязательным, вы
	 * можете заставить своих строителей ждать явного запроса на сброс из кода
	 * клиента, прежде чем избавиться от предыдущего результата.
	 */

	 /**
	  * Please be careful here with the memory ownership. Once you call
	  * GetProduct the user of this function is responsable to release this
	  * memory. Here could be a better option to use smart pointers to avoid
	  * memory leaks
	  */

	House* GetProduct() {
		House* result = this->product;
        this->Reset();
        return result;
    }
};
/**
 * Директор отвечает только за выполнение шагов построения в определённой
 * последовательности. Это полезно при производстве продуктов в определённом
 * порядке или особой конфигурации. Строго говоря, класс Директор необязателен,
 * так как клиент может напрямую управлять строителями.
 */
class HouseDirector {
private:
	HouseBuilder* m_Builder_;
public:
	void Construct();

	void set_builder(HouseBuilder* builder)
	{
		if(builder)
			this->m_Builder_ = builder;
	}

	void BuildMinimalViableProduct() {
		this->m_Builder_->ProducePartA();
	}

	void BuildFullFeaturedProduct() {
		//this->m_Builder_->ProducePartA();
		//this->m_Builder_->ProducePartB();
		this->m_Builder_->ProducePartC();
	}
};