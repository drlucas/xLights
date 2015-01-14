#ifndef XLIGHTSXMLFILE_H
#define XLIGHTSXMLFILE_H

#include <wx/filename.h>
#include <wx/xml/xml.h>
#include <wx/textctrl.h>

class xLightsXmlFile : public wxFileName
{
    public:
        xLightsXmlFile();
        virtual ~xLightsXmlFile();

        enum HEADER_INFO_TYPES
        {
            AUTHOR,
            AUTHOR_EMAIL,
            WEBSITE,
            SONG,
            ARTIST,
            ALBUM,
            URL,
            COMMENT,
            NUM_TYPES
        };
        void Load();
        void Save(wxTextCtrl* log);
        void SetHeaderInfo(wxArrayString info);
        wxString GetHeaderInfo(HEADER_INFO_TYPES val) { return header_info[val]; }
        void Clear();
        bool IsLoaded() { return is_loaded; }
        int GetNumModels() { return models.GetCount(); }
        const wxString GetVersion() { return version_string; };
        bool NeedsConversion() { return needs_conversion; }
    protected:
    private:
        wxArrayString models;
        wxArrayString timing_protection;
        wxArrayString timing;
        wxArrayString label_protection;
        wxArrayString labels;
        wxArrayString effect_protection;
        wxArrayString effects;
        wxXmlDocument seqDocument;
        wxArrayString header_info;
        bool is_loaded;
        bool needs_conversion;
        wxString version_string;
        wxString latest_version;

};

#endif // XLIGHTSXMLFILE_H