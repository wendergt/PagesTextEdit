#ifndef PAGEMETRICS_H
#define PAGEMETRICS_H

#include <QString>
#include <QSizeF>
#include <QMarginsF>
#include <QPageSize>

class QPaintDevice;


/**
 * @brief Класс метрик страницы
 */
class PageMetrics
{
public:
	PageMetrics(QPaintDevice* _device,
				QPageSize::PageSizeId _pageFormat = QPageSize::A4,
				QMarginsF _mmMargins = QMarginsF());

	/**
	 * @brief Обновить метрики
	 */
	void update(QPageSize::PageSizeId _pageFormat,
				QMarginsF _mmPageMargins = QMarginsF());

	/**
	 * @brief Методы доступа к параметрам страницы
	 */
	/** @{ */
	QPageSize::PageSizeId pageFormat() const { return m_pageFormat; }
	QSizeF mmPageSize() const { return m_mmPageSize; }
	QMarginsF mmPageMargins() const { return m_mmPageMargins; }
	QSizeF pxPageSize() const { return m_pxPageSize; }
	QMarginsF pxPageMargins() const { return m_pxPageMargins; }
	/** @} */

private:
	/**
	 * @brief Перевести миллиметры в пикселы
	 * @param _x указывает направление (горизонтальное - true или вертикальное - false), в котором
	 * необходимо произвести рассчёт
	 */
	qreal mmToPx(qreal _mm, bool _x) const;

private:
	/**
	 * @brief Устройство вывода, по которому определяется dpi
	 */
	QPaintDevice *m_device;

	/**
	 * @brief Формат страницы
	 */
	QPageSize::PageSizeId m_pageFormat;

	/**
	 * @brief Размеры в миллиметрах
	 */
	/** @{ */
	QSizeF m_mmPageSize;
	QMarginsF m_mmPageMargins;
	/** @} */

	/**
	 * @brief Размеры в пикселах
	 */
	/** @{ */
	QSizeF m_pxPageSize;
	QMarginsF m_pxPageMargins;
	/** @} */

};

#endif // PAGEMETRICS_H
