#include "DivinationCardLoader.h"
#include "rapidjson/document.h"
#include "rapidjson/error/en.h"

DivinationCardLoader::DivinationCardLoader()
{
    accessManager = QSharedPointer<QNetworkAccessManager>(new QNetworkAccessManager());
    cards->reserve(DIVINATION_CARDS_AMOUNT);
}
void DivinationCardLoader::load()
{
    currentReply = accessManager->get(QNetworkRequest(QUrl(url)));

    connect(accessManager.get(), &QNetworkAccessManager::finished, this, &DivinationCardLoader::readWebsiteContent);
    connect(currentReply, &QNetworkReply::errorOccurred, this, &DivinationCardLoader::onError);
}
QVector<DivinationCard>* DivinationCardLoader::get()
{
    return cards.get();
}
void DivinationCardLoader::readWebsiteContent()
{
    QString websiteContent = currentReply->readAll();
    rapidjson::Document jsonWebsiteContent;
    jsonWebsiteContent.Parse(websiteContent.toStdString().c_str());
    if(!jsonWebsiteContent.IsNull())
    {
        for(rapidjson::Value::ConstValueIterator iter = jsonWebsiteContent["lines"].Begin(); iter != jsonWebsiteContent["lines"].End(); ++iter)
        {
            DivinationCard card;
            card.name = (*iter)["artFilename"].GetString();
            card.reward = (*iter)["explicitModifiers"][0]["text"].GetString();
            card.chaosValue = (*iter)["chaosValue"].GetDouble();
            if((*iter).HasMember("stackSize"))
            {
                card.stackSize = (*iter)["stackSize"].GetInt();
            }
            else
            {
                card.stackSize = 1;
            }
            cards->push_back(card);
            qDebug() << card.reward;
        }
    }
}
void DivinationCardLoader::onError(QNetworkReply::NetworkError errorCode)
{
    qDebug() << errorCode;
}
